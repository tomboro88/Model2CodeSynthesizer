/**
 * @file 
 * 
 * @brief The SafeSm package source file.
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "SafeSm.h"
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Non-private function prototypes.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static bool safesm_sm1_exit_region2(safesm_sm1_t* const p_obj);
static bool safesm_sm1_exit_region4(safesm_sm1_t* const p_obj);
static bool safesm_sm1_exit_region3(safesm_sm1_t* const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a(safesm_sm1_t* const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a_region2(safesm_sm1_t* \
                                                       /**/const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a_region4(safesm_sm1_t* \
                                                       /**/const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a_state1(safesm_sm1_t* \
                                                      /**/const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a_state2(safesm_sm1_t* \
                                                      /**/const p_obj);

static sm_event_status_t safesm_sm1_dispatch_a_state5(safesm_sm1_t* \
                                                      /**/const p_obj);

static bool safesm_sm1_enter_junction5_a_7(safesm_sm1_t* const p_obj,\
                                           sm_event_status_t* const p_result);

static bool safesm_sm1_enter_junction3_a_7_4(safesm_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);

static bool safesm_sm1_enter_junction4_7_4_5(safesm_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);

static bool safesm_sm1_enter_junction2_7_4_5_2(safesm_sm1_t* const p_obj,\
                                               sm_event_status_t* \
                                               /**/const p_result);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
safesm_sm1_fifo_sizes[SAFESM_SM1_EVENT_COUNT] =
{
    SAFESM_SM1_A_CNT
};
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/**
 * @brief Enters the SafeState state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_safestate(safesm_sm1_t* const p_obj)
{
    p_obj->region2 = SAFESM_SM1_INITIAL2;
    p_obj->region4 = SAFESM_SM1_INITIAL3;
    p_obj->region3 = SAFESM_SM1_REGION3_INL;
    p_obj->region1 = SAFESM_SM1_SAFESTATE;
}

/**
 * @brief Enters the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_state1(safesm_sm1_t* const p_obj)
{
    p_obj->region1 = SAFESM_SM1_STATE1;
}

/**
 * @brief Enters the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_state2(safesm_sm1_t* const p_obj)
{
    p_obj->region2 = SAFESM_SM1_STATE2;
}

/**
 * @brief Enters the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_state5(safesm_sm1_t* const p_obj)
{
    p_obj->region4 = SAFESM_SM1_STATE5;
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_state3(safesm_sm1_t* const p_obj)
{
    p_obj->region1 = SAFESM_SM1_STATE3;
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_state4(safesm_sm1_t* const p_obj)
{
    p_obj->region3 = SAFESM_SM1_STATE4;
}

/**
 * @brief Implements entry of the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_region4(safesm_sm1_t* const p_obj)
{
    p_obj->region4 = SAFESM_SM1_INITIAL3;
    safesm_sm1_enter_state5(p_obj);
}

/**
 * @brief Implements entry of the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_region2(safesm_sm1_t* const p_obj)
{
    p_obj->region2 = SAFESM_SM1_INITIAL2;
    safesm_sm1_enter_state2(p_obj);
    safesm_sm1_enter_region4(p_obj);
}

/**
 * @brief Implements entry of the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_region3(safesm_sm1_t* const p_obj)
{
    p_obj->region3 = SAFESM_SM1_REGION3_INL;
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_enter_region1(safesm_sm1_t* const p_obj)
{
    p_obj->region1 = SAFESM_SM1_INITIAL1;
    safesm_sm1_enter_state1(p_obj);
    safesm_sm1_enter_region2(p_obj);
}

/**
 * @brief Exits the SafeState state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_exit_safestate(safesm_sm1_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region1 = SAFESM_SM1_INITIAL1;
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline bool
safesm_sm1_exit_state1(safesm_sm1_t* const p_obj)
{
    bool b_is_exit_ok = safesm_sm1_exit_region2(p_obj);
    // Mark the state has already exited.
    p_obj->region1 = SAFESM_SM1_INITIAL1;

    return b_is_exit_ok;
}

/**
 * @brief Exits the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline bool
safesm_sm1_exit_state2(safesm_sm1_t* const p_obj)
{
    bool b_is_exit_ok = safesm_sm1_exit_region4(p_obj);
    // Mark the state has already exited.
    p_obj->region2 = SAFESM_SM1_INITIAL2;

    return b_is_exit_ok;
}

/**
 * @brief Exits the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_exit_state5(safesm_sm1_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region4 = SAFESM_SM1_INITIAL3;
}

/**
 * @brief Exits the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline bool
safesm_sm1_exit_state3(safesm_sm1_t* const p_obj)
{
    bool b_is_exit_ok = safesm_sm1_exit_region3(p_obj);
    // Mark the state has already exited.
    p_obj->region1 = SAFESM_SM1_INITIAL1;

    return b_is_exit_ok;
}

/**
 * @brief Exits the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
safesm_sm1_exit_state4(safesm_sm1_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region3 = SAFESM_SM1_REGION3_INL;
}

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
safesm_sm1_a(safesm_sm1_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) SAFESM_SM1_A);
    }
    
    return b_is_added;
}

/**
 * @brief The initialization function of the standalone StateMachine sm.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
safesm_sm1_init(safesm_sm1_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        b_is_created = true;
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[SAFESM_SM1_A].fifo),
                        SAFESM_SM1_A_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[SAFESM_SM1_A].p_next_events
                       = p_obj->event_pool.a_next_events;
        
        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = SAFESM_SM1_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};
        
        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = b_is_created
                        && event_pool_initialize(&p_obj->event_pool.manager,\
                                                 p_obj->event_pool.fifo_pool,\
                                                 safesm_sm1_fifo_sizes,\
                                                 SAFESM_SM1_EVENT_COUNT);
        
        p_obj->region1                   = SAFESM_SM1_INITIAL1;
        p_obj->region2                   = SAFESM_SM1_INITIAL2;
        p_obj->region4                   = SAFESM_SM1_INITIAL3;
        p_obj->region3                   = SAFESM_SM1_REGION3_INL;
        
        /* Execute the initial transition.*/
        safesm_sm1_enter_region1(p_obj);
    }

    return b_is_created;
}

/**
 * @brief Fetches the first event pending in the event pool.
 * @details This function is separated to allow the user to call it from an
 * enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object.
 * @returns true, when an event was fetched from the event pool and is waiting
 * for processing.
 * @returns false, when the event pool is empty, or the p_obj is NULL.
 */
bool
safesm_sm1_fetch_event(safesm_sm1_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                    (event_pool_locator_t)
                    {.event_type = SAFESM_SM1_EVENT_COUNT,
                     .event_index = (~((fifo_size_t) 0u))};
                b_is_new_event =
                    event_pool_get_first_head(&p_obj->event_pool.manager,\
                                              &p_obj->event_pool.fetched_event);
                break;
            case SM_EVENT_STATUS_PENDING:
                b_is_new_event = true;
                break;
            default:
                break;
        }

        if(b_is_new_event)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_PENDING;
        }
    }

    return b_is_new_event;
}

/**
 * @brief Executes the proper action corresponding to the event fetched from the
 * event pool.
 * @details This function was separated from the other two (*fetch* and
 * *release*) functions, because in normal scenario this function doesn't need
 * to be called from a critical section. Since the event at the head of the
 * event pool has already been fetched, no action on the event pool is able to
 * modify the event data contents. Because the event data is still in the event
 * pool, there is no need for an additional temporary buffer for keeping a copy
 * of the event data (which could be troublesome due to separate data types for
 * each event).
 * To access the required event data it is enough to use information in the
 * 'event_pool.fetched_event' field. This approach saves memory and has no need
 * of event data copying, but may be only a little slower when accessing the
 * event data due to retrieving information from the 'event_pool.fetched_event'
 * field.
 * @returns true when a fetched event was waiting for processing.
 * @returns false when there was no event waiting for processing or the p_obj
 * was NULL.
 */
bool
safesm_sm1_dispatch_event(safesm_sm1_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case SAFESM_SM1_A:
                temp_status = safesm_sm1_dispatch_a(p_obj);
                break;
            default:
                break;
        }

        p_obj->event_pool.event_proc_status = temp_status;
        b_is_new_event = true;
    }

    return b_is_new_event;
}

/**
 * @brief Removes the processed event from the event pool.
 * @details This function is separated to allow the user to call it from an
 * enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object of the sm1 class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in the
 * event pool.
 */
bool
safesm_sm1_release_event(safesm_sm1_t* const p_obj)
{
    bool b_is_released = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING < p_obj->event_pool.event_proc_status)
        && (SM_EVENT_STATUS_DISPATCHED > p_obj->event_pool.event_proc_status))
    {
        b_is_released = event_pool_dequeue(&p_obj->event_pool.manager);

        if(b_is_released)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        }
    }

    return b_is_released;
}

/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/**
 * @brief Exits the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static bool
safesm_sm1_exit_region2(safesm_sm1_t* const p_obj)
{
    bool b_exit_ok = true;

    switch(p_obj->region2)
    {
        case SAFESM_SM1_STATE2:
            b_exit_ok = safesm_sm1_exit_state2(p_obj);
            break;
        case SAFESM_SM1_INITIAL2:
            break;
        default:
            b_exit_ok = false;
            break;
    }

    return b_exit_ok;
}

/**
 * @brief Exits the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static bool
safesm_sm1_exit_region4(safesm_sm1_t* const p_obj)
{
    bool b_exit_ok = true;

    switch(p_obj->region4)
    {
        case SAFESM_SM1_STATE5:
            safesm_sm1_exit_state5(p_obj);
            break;
        case SAFESM_SM1_INITIAL3:
            break;
        default:
            b_exit_ok = false;
            break;
    }

    return b_exit_ok;
}

/**
 * @brief Exits the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static bool
safesm_sm1_exit_region3(safesm_sm1_t* const p_obj)
{
    bool b_exit_ok = true;

    switch(p_obj->region3)
    {
        case SAFESM_SM1_STATE4:
            safesm_sm1_exit_state4(p_obj);
            break;
        case SAFESM_SM1_REGION3_INL:
            break;
        default:
            b_exit_ok = false;
            break;
    }

    return b_exit_ok;
}

/**
 * @brief Implements a event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case SAFESM_SM1_SAFESTATE:
            break;
        case SAFESM_SM1_STATE1:
            result = safesm_sm1_dispatch_a_state1(p_obj);
            break;
        case SAFESM_SM1_STATE3:
            break;
        default:
            safesm_sm1_enter_safestate(p_obj);
            result = SM_EVENT_STATUS_SAFESTATE;
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a_region2(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case SAFESM_SM1_STATE2:
            result = safesm_sm1_dispatch_a_state2(p_obj);
            break;
        default:
            safesm_sm1_enter_safestate(p_obj);
            result = SM_EVENT_STATUS_SAFESTATE;
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region4 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a_region4(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4)
    {
        case SAFESM_SM1_STATE5:
            result = safesm_sm1_dispatch_a_state5(p_obj);
            break;
        default:
            safesm_sm1_enter_safestate(p_obj);
            result = SM_EVENT_STATUS_SAFESTATE;
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a_state1(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = safesm_sm1_dispatch_a_region2(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a_state2(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = safesm_sm1_dispatch_a_region4(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
safesm_sm1_dispatch_a_state5(safesm_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(safesm_sm1_enter_junction5_a_7(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements entry of the Junction5 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State5, Junction5.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
safesm_sm1_enter_junction5_a_7(safesm_sm1_t* const p_obj,\
                               sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(safesm_sm1_enter_junction3_a_7_4(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction3 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State5, Junction5, Junction3.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
safesm_sm1_enter_junction3_a_7_4(safesm_sm1_t* const p_obj,\
                                 sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(safesm_sm1_enter_junction4_7_4_5(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction4 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State5, Junction5, Junction3, Junction4.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
safesm_sm1_enter_junction4_7_4_5(safesm_sm1_t* const p_obj,\
                                 sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(safesm_sm1_enter_junction2_7_4_5_2(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction2 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State5, Junction5, Junction3, Junction4,
 * Junction2.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
safesm_sm1_enter_junction2_7_4_5_2(safesm_sm1_t* const p_obj,\
                                   sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    safesm_sm1_exit_state5(p_obj);
    printf("State5 to Junction5\n");
    bool b_is_exit_ok = safesm_sm1_exit_state2(p_obj);
    
    if(b_is_exit_ok)
    {
        printf("Junction5 to Junction3\n");
        b_is_exit_ok = b_is_exit_ok && safesm_sm1_exit_state1(p_obj);
    }
    
    if(b_is_exit_ok)
    {
        printf("Junction3 to Junction4\n");
        printf("Junction4 to Junction2\n");
        safesm_sm1_enter_state3(p_obj);
        printf("Junction2 to State4\n");
        safesm_sm1_enter_state4(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
    }
    else
    {
        safesm_sm1_enter_safestate(p_obj);
        *p_result = SM_EVENT_STATUS_SAFESTATE;
    }

    return b_is_handled;
}

/*** end of file ***/
