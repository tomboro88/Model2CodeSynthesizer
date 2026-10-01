/**
 * @file 
 * 
 * @brief The standalone package source file.
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
#include "standalone.h"
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

static sm_event_status_t standalone_sm_dispatch_a(standalone_sm_t* const p_obj);
static sm_event_status_t standalone_sm_dispatch_b(standalone_sm_t* const p_obj);


static sm_event_status_t standalone_sm_dispatch_a_state2(standalone_sm_t* \
                                                         /**/const p_obj);
static sm_event_status_t standalone_sm_dispatch_b_state4(standalone_sm_t* \
                                                         /**/const p_obj);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
standalone_sm_fifo_sizes[STANDALONE_SM_EVENT_COUNT] =
{
    STANDALONE_SM_A_CNT,
    STANDALONE_SM_B_CNT
};
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/**
 * @brief Enters the State2 state of the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
standalone_sm_enter_state2(standalone_sm_t* const p_obj)
{
    p_obj->region1 = STANDALONE_SM_STATE2;
}

/**
 * @brief Enters the State4 state of the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
standalone_sm_enter_state4(standalone_sm_t* const p_obj)
{
    p_obj->region1 = STANDALONE_SM_STATE4;
}

/**
 * @brief Enters the State5 state of the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
standalone_sm_enter_state5(standalone_sm_t* const p_obj)
{
    p_obj->region1 = STANDALONE_SM_STATE5;
}

/**
 * @brief Implements entry of the Region1 region of the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
standalone_sm_enter_region1(standalone_sm_t* const p_obj)
{
    p_obj->region1 = STANDALONE_SM_INITIAL1;
    standalone_sm_enter_state2(p_obj);
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
standalone_sm_a(standalone_sm_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) STANDALONE_SM_A);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] b 
 */
bool
standalone_sm_b(standalone_sm_t* const p_obj, bool const b)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        fifo_size_t tail = p_obj->event_pool.fifo_pool[STANDALONE_SM_B].fifo.tail;
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) STANDALONE_SM_B);
        if(b_is_added)
        {
            standalone_sm_b_t * p_b_args = &p_obj->event_pool.b_args[tail];
            p_b_args->b = b;
        }
    }
    
    return b_is_added;
}

/**
 * @brief The initialization function of the standalone StateMachine sm.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
standalone_sm_init(standalone_sm_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        b_is_created = true;
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[STANDALONE_SM_A].fifo),
                        STANDALONE_SM_A_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[STANDALONE_SM_A].p_next_events
                       = p_obj->event_pool.a_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[STANDALONE_SM_B].fifo),
                        STANDALONE_SM_B_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[STANDALONE_SM_B].p_next_events
                       = p_obj->event_pool.b_next_events;
        
        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = STANDALONE_SM_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};
        
        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = b_is_created
                        && event_pool_initialize(&p_obj->event_pool.manager,\
                                                 p_obj->event_pool.fifo_pool,\
                                                 standalone_sm_fifo_sizes,\
                                                 STANDALONE_SM_EVENT_COUNT);
        
        p_obj->region1                   = STANDALONE_SM_INITIAL1;
        
        /* Execute the initial transition.*/
        standalone_sm_enter_region1(p_obj);
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
standalone_sm_fetch_event(standalone_sm_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                    (event_pool_locator_t)
                    {.event_type = STANDALONE_SM_EVENT_COUNT,
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
standalone_sm_dispatch_event(standalone_sm_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case STANDALONE_SM_A:
                temp_status = standalone_sm_dispatch_a(p_obj);
                break;
            case STANDALONE_SM_B:
                temp_status = standalone_sm_dispatch_b(p_obj);
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
 * @param [in] p_obj The pointer to the self object of the sm class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in the
 * event pool.
 */
bool
standalone_sm_release_event(standalone_sm_t* const p_obj)
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
 * @brief Implements a event handling by the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
standalone_sm_dispatch_a(standalone_sm_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case STANDALONE_SM_STATE2:
            result = standalone_sm_dispatch_a_state2(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
standalone_sm_dispatch_b(standalone_sm_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case STANDALONE_SM_STATE4:
            result = standalone_sm_dispatch_b_state4(p_obj);
            break;
        default:
            break;
    }

    return result;
}


/**
 * @brief Implements a event handling by the State2 state of the sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
standalone_sm_dispatch_a_state2(standalone_sm_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    standalone_sm_enter_state4(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State4 state of the sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
standalone_sm_dispatch_b_state4(standalone_sm_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    standalone_sm_enter_state5(p_obj);

    return result;
}

/*** end of file ***/
