#pragma once
#include <GLFW/glfw3.h>
#include <bitset>
#include <functional>
#include <map>
#include <set>
#include <type_traits>
#include <cstring>

#include "math/mathlib.h"

namespace Engine
{

/**
 * @brief Enum of action types which can be bound to one or several input events
 *        like key presses or mouse movement (user side) and can be bound to callbacks
 *        which react to the triggering of these input events (implementation side).
 */
enum class ActionType
{
    PauseGame = 0,

    CameraFirstPerson,
    CameraFree,
    CameraViewer,
    CameraThirdPerson,

    FirstPersonMoveForward,
    FirstPersonMoveRight,
    FirstPersonLookHorizontal,
    FirstPersonLookVertical,

    FreeMoveForward,
    FreeMoveRight,
    FreeMoveUp,
    FreeLookHorizontal,
    FreeLookVertical,

    ViewerHorizontal,
    ViewerVertical,
    ViewerPan,
    ViewerZoom,
    ViewerRotate,
    ViewerClick,
    ViewerMouseWheel,

    PlayerForward,
    PlayerBackward,
    PlayerTurnLeft,
    PlayerTurnRight,
    PlayerStrafeLeft,
    PlayerStrafeRight,
    PlayerDrawWeaponMelee,
    PlayerAttackFist,

    DebugMoveSpeed,

    WeaponAnimationAttackLeft,
    WeaponAnimationAttackRight,
    WeaponAnimationRun,
    WeaponAnimationBackpedal,
    WeaponAnimationAttack,

    AllNpcDrawWeapon,
    AllNpcUndrawWeapon,
    AllNpcAttackFront,

//    WeaponModeNone,
//    WeaponMode1h,
//    WeaponMode2h,
//    WeaponModeBow,
//    WeaponModeCrossBow,
//    WeaponModeMagic,
//    WeaponModeFist,

    DebugSkySpeed,

    Count
};

/**
 * @brief This class represents an action in the form of a callback function.
 *        It is bound to one or several action types by the Input class.
 */
class Action
{
    friend class Input;

public:
    /**
     * @brief Sets the enabled state of this action. A disabled action's
     *        callback function will never be called.
     * @param enabled True for enabled, false for disabled.
     */
    void setEnabled(bool enabled);

private:
    /**
     * @brief Constructs this action with a callback function. The action is set to enabled by default.
     * @param func Function which is called when a binding is fired. The boolean determines whether the binding was triggered,
     *             the float represents the intensity of the key press or mouse movement etc.
     */
    Action(std::function<void(bool /*triggered*/, float /*intensity*/)> func);

    /**
     * @brief isEnabled Flag determining whether this action's callback function should be called when it's binding is triggered.
     */
    bool isEnabled;
    /**
     * @brief function The callback function.
     */
    std::function<void(bool /*triggered*/, float /*intensity*/)> function;
};

/**
 * @brief The Input class is the main class for managing user inputs. It provides a mechanism which abstracts the actual code that reacts
 *        on user key presses and mouse / joystick movement (implementation side) from the binding to specific input methods (user side).
 *        The implementor should add the desired action types to the enum and call "::"registerAction and the user should call "::"binKey
 *        and similar functions to bind keys and other input methods.
 */
class Input
{
public:
    /**
     * @brief Enums defining the axes a usual mouse provides. CursorX/Y correspond to the movement of the mouse itself and ScrollX/Y correspond
     *        to the axes of a scrolling device. Most mice provide at least the ScrollY axis (mouse wheel).
     */
    enum class MouseAxis
    {
        CursorX = 0,
        CursorY,
        ScrollX,
        ScrollY,
        Count
    };

public:
    /**
     * @brief Register an action for a previously defined action type.
     * @param actionType The action type whose bindings cause the passed callback to be called.
     * @param function The callback function.
     * @return A pointer to the created Action instance to call Action::setEnabeld. The storage is managed in the Input class.
     */
    static Action* registerAction( ActionType actionType, std::function<void(bool /*triggered*/, float /*intensity*/)> function);

    /**
     * @brief Remove a previously registered action.
     * @param actionType The action type which was registered
     * @param action The registered action
     * @return Returns true if the passed combination of action type and action was found and deleted, false otherwise.
     */
    static bool removeAction(ActionType actionType, Action* action);

    /**
     * @brief Checks all bindings against the input and calls the corresponding registered actions.
     */
    static void fireBindings();

    /**
     * @brief Turns the mouse lock, which means that no cursors is visible and mouse movement is unlimited, on or off.
     * @param True for mouse lock on, false for off.
     */
    static void setMouseLock(bool mouseLock);

    /**
     * @brief Returns the actual mouse cursor coordinates.
     * @return Position of the cursor in normalized device coordinates.
     */
    static Math::float2 getMouseCoordinates();

protected:
    static void bindKey(int key, ActionType actionType, bool isContinuous, bool isInverted = false);
    static void bindMouseButton(int mouseButton, ActionType actionType, bool isContinuous, bool isInverted = false);
    static void bindMouseAxis(MouseAxis mouseAxis, ActionType actionType, bool isContinuous, bool isInverted = false);

    static void keyEvent(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouseButtonEvent(GLFWwindow *window, int button, int action, int mods);
    static void mouseMoveEvent(GLFWwindow *window, double xPos, double yPos);
    static void scrollEvent(GLFWwindow *window, double xOffset, double yOffset);

    static void windowSizeEvent(GLFWwindow *window, int width, int height);

    static void setMouseLockCallback(std::function<void(bool /* lock */)> callback);

private:
    /**
     * @brief The ActionBinding struct
     */
    struct ActionBinding
    {
        /**
         * @brief ActionBinding
         * @param actionType
         * @param isContinuous
         * @param isInverted
         */
        ActionBinding(ActionType actionType, bool isContinuous, bool isInverted);
        bool operator<(const ActionBinding &other) const;

        ActionType actionType;
        bool isContinuous;
        bool isInverted;
    };

    static std::set<std::pair<ActionBinding, int /*key*/>> actionBindingToKeySet;
    static std::set<std::pair<ActionBinding, int /*mouseButton*/>> actionBindingToMouseButtonSet;
    static std::set<std::pair<ActionBinding, MouseAxis>> actionBindingToMouseAxisSet;

    static std::multimap<ActionType, Action> actionTypeToActionMap;

    static std::bitset<GLFW_KEY_LAST + 1> keyState;
    static std::bitset<GLFW_KEY_LAST + 1> keyTriggered;

    static std::bitset<GLFW_MOUSE_BUTTON_LAST + 1> mouseButtonState;
    static std::bitset<GLFW_MOUSE_BUTTON_LAST + 1> mouseButtonTriggered;

    static float axisPosition[static_cast<std::size_t>(MouseAxis::Count)];
    static std::bitset<static_cast<std::size_t>(MouseAxis::Count)> mouseAxisState;
    static std::bitset<static_cast<std::size_t>(MouseAxis::Count)> mouseAxisTriggered;

    static float mouseSensitivity;
    static Math::float2 mousePosition;
    static bool isMouseLocked;
    static std::function<void(bool /* lock */)> mouseLockCallback;
    static float windowHalfWidth;
    static float windowHalfHeight;
};
}
