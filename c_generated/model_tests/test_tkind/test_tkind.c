/**
 * @file 
 * 
 * @brief The test_tkind package source file.
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
#include "test_tkind.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
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

extern void tkind_ctest_set_uint_incr(tkind_cbase1_t* const p_obj,\
                                      uint32_t const param1);
extern float tkind_ctest_get_flt_from_uint(tkind_cbase2_t* const p_obj);

/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void test_tkind_a_state2_sm_exit_region1(test_tkind_a_state2_sm_t* \
                                                /**/const p_obj);

static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call\
       (test_tkind_a_state2_sm_t* const p_obj);

static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call_region1\
       (test_tkind_a_state2_sm_t* const p_obj);

static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call_state10\
       (test_tkind_a_state2_sm_t* const p_obj);
static sm_event_status_t test_tkind_a_state2_sm_dispatch_any_state10\
       (test_tkind_a_state2_sm_t* const p_obj);

static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call_effect_bhv\
       (test_tkind_a_state2_sm_t* const p_obj);
static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call_exit_bhv\
       (test_tkind_a_state2_sm_t* const p_obj);
static sm_event_status_t test_tkind_a_state2_sm_dispatch_rec_call_init\
       (test_tkind_a_state2_sm_t* const p_obj);

static void test_tkind_ainstate2_case(test_tkind_ainstate2_t* const p_obj);

static void test_tkind_ctest_fixture_invoke_a_state2_sm\
       (test_tkind_ctest_fixture_t* const p_obj);

static void test_tkind_ctest_fixture_init_df(test_tkind_ctest_fixture_t* \
                                             /**/const p_obj);

static void test_tkind_ctest_logger_rec_bhv(plogger_logger_t* const p_obj,\
                                            const char* const p_str);
static void test_tkind_ctest_logger_recdbl_bhv(plogger_logger_t* const p_obj,\
                                               const char* const p_str,\
                                               double const dbl_param);
static void test_tkind_ctest_logger_recu16c_bhv(plogger_logger_t* const p_obj,\
                                                const char* const p_str,\
                                                uint16_t const u16_param,\
                                                char const char_param);

static void test_tkind_enterstate2_setup(test_tkind_enterstate2_t* const p_obj);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief The initialized virtual table for the test_tkind_ctest_fixture_s
 * struct.
 */
static const test_tkind_ctest_fixture_vt_t test_tkind_ctest_fixture_vtable = 
{
    .ctest.cbase1.p_setuintprop      = tkind_ctest_set_uint_incr,
    .ctest.cbase2.p_getfloatprop     = tkind_ctest_get_flt_from_uint
};

/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
test_tkind_ctest_fixture_fifo_sizes[TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT] =
{
    TEST_TKIND_CTEST_FIXTURE_REC_CALL_CNT
};
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/**
 * @brief Enters the State10 state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_state10(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_STATE10;
}

/**
 * @brief Enters the effect_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_effect_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_EFFECT_BHV;
}

/**
 * @brief Enters the exit_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_exit_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_EXIT_BHV;
}

/**
 * @brief Enters the init state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_init(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INIT;
}

/**
 * @brief Enters the entry_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_entry_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_ENTRY_BHV;
    p_obj->p_context->b_is_completed = true;
}

/**
 * @brief Implements entry of the Region1 region of the a_state2_sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_region1(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL1;
    test_tkind_a_state2_sm_enter_init(p_obj);
}

/**
 * @brief Implements entry of the Region1 region of the a_state2_sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_enter_region1(test_tkind_a_state2_sm_t* const p_obj)
{
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL2;
    test_tkind_a_state2_sm_enter_state10(p_obj);
    test_tkind_a_state2_sm_enter_region1(p_obj);
}

/**
 * @brief Exits the State10 state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_exit_state10(test_tkind_a_state2_sm_t* const p_obj)
{
    test_tkind_a_state2_sm_exit_region1(p_obj);
    // Mark the state has already exited.
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL2;
}

/**
 * @brief Exits the effect_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_exit_effect_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL1;
}

/**
 * @brief Exits the exit_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_exit_exit_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL1;
}

/**
 * @brief Exits the init state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_exit_init(test_tkind_a_state2_sm_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL1;
}

/**
 * @brief Exits the entry_bhv state of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
test_tkind_a_state2_sm_exit_entry_bhv(test_tkind_a_state2_sm_t* const p_obj)
{
    // Mark the state has already exited.
    p_obj->region1 = TEST_TKIND_A_STATE2_SM_INITIAL1;
}

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
test_tkind_ctest_fixture_init(test_tkind_ctest_fixture_t* const p_obj)
{
    bool b_is_created = false;

    if((NULL != p_obj)
        && tkind_ctest_init(&p_obj->ctest, p_logger))
    {
        test_tkind_ctest_fixture_init_df(p_obj);
        b_is_created = true;
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TEST_TKIND_CTEST_FIXTURE_REC_CALL].fifo),
                        TEST_TKIND_CTEST_FIXTURE_REC_CALL_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TEST_TKIND_CTEST_FIXTURE_REC_CALL].p_next_events
                       = p_obj->event_pool.rec_call_next_events;
        
        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};
        
        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = b_is_created
                        && event_pool_initialize(&p_obj->event_pool.manager,\
                                p_obj->event_pool.fifo_pool,\
                                test_tkind_ctest_fixture_fifo_sizes,\
                                TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT);
        
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str 
 */
bool
test_tkind_ctest_fixture_rec(test_tkind_ctest_fixture_t* const p_obj,\
                             char const p_str)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        fifo_size_t tail = p_obj->event_pool.fifo_pool[TEST_TKIND_CTEST_FIXTURE_REC_CALL].fifo.tail;
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TEST_TKIND_CTEST_FIXTURE_REC_CALL);
        if(b_is_added)
        {
            test_tkind_ctest_fixture_rec_call_t * p_rec_call_args = &p_obj->event_pool.rec_call_args[tail];
            p_rec_call_args->p_str = p_str;
        }
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str 
 * @param [in] dbl_param A double parameter that will be logged.
 */
bool
test_tkind_ctest_fixture_recdbl(test_tkind_ctest_fixture_t* const p_obj,\
                                char const p_str, double const dbl_param)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str 
 * @param [in] u16_param 
 * @param [in] char_param 
 */
bool
test_tkind_ctest_fixture_recu16c(test_tkind_ctest_fixture_t* const p_obj,\
                                 char const p_str, uint16_t const u16_param,\
                                 char const char_param)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
test_tkind_ctest_fixture_drain_events(test_tkind_ctest_fixture_t* const p_obj)
{
    bool b_is_event_pending = false;
    
    do{
        b_is_event_pending = tkind_ctest_fetch_event(p_obj);
    
        if(b_is_event_pending)
        {
            TEST_ASSERT_TRUE(tkind_ctest_dispatch_event(p_obj)
                && tkind_ctest_release_event(p_obj));
        }
    }while(b_is_event_pending);
    
    do{
        b_is_event_pending = test_tkind_ctest_fixture_fetch_event(p_obj);
    
        if(b_is_event_pending)
        {
            TEST_ASSERT_TRUE(test_tkind_ctest_fixture_dispatch_event(p_obj)
                && test_tkind_ctest_fixture_release_event(p_obj));
        }
    }while(b_is_event_pending);
    
    TEST_ASSERT_TRUE(p_obj->b_is_completed);
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
test_tkind_ctest_fixture_fetch_event(test_tkind_ctest_fixture_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                    (event_pool_locator_t)
                    {.event_type = TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT,
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
test_tkind_ctest_fixture_dispatch_event(test_tkind_ctest_fixture_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case TEST_TKIND_CTEST_FIXTURE_REC_CALL:
                temp_status = test_tkind_a_state2_sm_dispatch_rec_call\
                       (&p_obj->a_state2_sm);
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
 * @param [in] p_obj The pointer to the self object of the ctest_fixture class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in the
 * event pool.
 */
bool
test_tkind_ctest_fixture_release_event(test_tkind_ctest_fixture_t* const p_obj)
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
 * @brief Exits the Region1 region of the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
test_tkind_a_state2_sm_exit_region1(test_tkind_a_state2_sm_t* const p_obj)
{
    switch(p_obj->region1)
    {
        case TEST_TKIND_A_STATE2_SM_EFFECT_BHV:
            test_tkind_a_state2_sm_exit_effect_bhv(p_obj);
            break;
        case TEST_TKIND_A_STATE2_SM_EXIT_BHV:
            test_tkind_a_state2_sm_exit_exit_bhv(p_obj);
            break;
        case TEST_TKIND_A_STATE2_SM_INIT:
            test_tkind_a_state2_sm_exit_init(p_obj);
            break;
        case TEST_TKIND_A_STATE2_SM_ENTRY_BHV:
            test_tkind_a_state2_sm_exit_entry_bhv(p_obj);
            break;
        default:
            break;
    }
}

/**
 * @brief Implements rec_call event handling by the a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call(test_tkind_a_state2_sm_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TEST_TKIND_A_STATE2_SM_STATE10:
            result = test_tkind_a_state2_sm_dispatch_rec_call_state10(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements rec_call event handling by the Region1 region of the
 * a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call_region1(test_tkind_a_state2_sm_t* \
                                                 /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TEST_TKIND_A_STATE2_SM_EFFECT_BHV:
            result = test_tkind_a_state2_sm_dispatch_rec_call_effect_bhv(p_obj);
            break;
        case TEST_TKIND_A_STATE2_SM_EXIT_BHV:
            result = test_tkind_a_state2_sm_dispatch_rec_call_exit_bhv(p_obj);
            break;
        case TEST_TKIND_A_STATE2_SM_INIT:
            result = test_tkind_a_state2_sm_dispatch_rec_call_init(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements rec_call event handling by the State10 state of the
 * a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call_state10(test_tkind_a_state2_sm_t* \
                                                 /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = test_tkind_a_state2_sm_dispatch_rec_call_region1(p_obj);

    if(SM_EVENT_STATUS_IGNORED == result)
    {
        result = test_tkind_a_state2_sm_dispatch_any_state10(p_obj);
    }

    return result;
}

/**
 * @brief Implements Any event handling by the State10 state of the a_state2_sm
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_any_state10(test_tkind_a_state2_sm_t* \
                                            /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_SAMESTATE;

    p_obj->p_context->b_is_completed = false;
    TEST_FAIL_MESSAGE("Unpredicted event occurred!");

    return result;
}

/**
 * @brief Implements rec_call event handling by the effect_bhv state of the
 * a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call_effect_bhv(test_tkind_a_state2_sm_t* \
                                                    /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    test_tkind_a_state2_sm_exit_effect_bhv(p_obj);
    TEST_ASSERT_EQUAL_STRING( "Enter State3\n", p_str);
    test_tkind_a_state2_sm_enter_entry_bhv(p_obj);

    return result;
}

/**
 * @brief Implements rec_call event handling by the exit_bhv state of the
 * a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call_exit_bhv(test_tkind_a_state2_sm_t* \
                                                  /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    test_tkind_a_state2_sm_exit_exit_bhv(p_obj);
    TEST_ASSERT_EQUAL_STRING("State2 to State3\n", p_str);
    test_tkind_a_state2_sm_enter_effect_bhv(p_obj);

    return result;
}

/**
 * @brief Implements rec_call event handling by the init state of the
 * a_state2_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
test_tkind_a_state2_sm_dispatch_rec_call_init(test_tkind_a_state2_sm_t* \
                                              /**/const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    test_tkind_a_state2_sm_exit_init(p_obj);
    TEST_ASSERT_EQUAL_STRING("Exit State2\n", p_str);
    test_tkind_a_state2_sm_enter_exit_bhv(p_obj);

    return result;
}

/**
 */
static void
test_tkind_ainstate2_case(test_tkind_ainstate2_t* const p_obj)
{
    TEST_ASSERT_TRUE(tkind_ctest_a(&ctest_sut.ctest));
    test_tkind_ctest_fixture_drain_events(&ctest_sut);
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the test_tkind_ctest_fixture_s struct. Generated automatically for properties
 * for which a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
test_tkind_ctest_fixture_init_df(test_tkind_ctest_fixture_t* const p_obj)
{
    p_obj->b_is_completed            = false;
    p_obj->ctest.cbase1.p_vtable     = &test_tkind_ctest_fixture_vtable.ctest
                                        .cbase1;
    p_obj->ctest.cbase2.p_vtable     = &test_tkind_ctest_fixture_vtable.ctest
                                        .cbase2;
}

/**
 */
static void
test_tkind_ctest_fixture_invoke_a_state2_sm(test_tkind_ctest_fixture_t* \
                                            /**/const p_obj)
{
    p_obj->a_state2_sm.p_context     = p_obj;
    p_obj->a_state2_sm.region1       = TEST_TKIND_A_STATE2_SM_INITIAL2;
    p_obj->a_state2_sm.region1       = TEST_TKIND_A_STATE2_SM_INITIAL1;
    
    /* Execute the initial transition.*/
    test_tkind_a_state2_sm_enter_region1(&p_obj->a_state2_sm);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 */
static void
test_tkind_ctest_logger_rec_bhv(plogger_logger_t* const p_obj,\
                                const char* const p_str)
{
    test_tkind_ctest_fix_rec(&p_obj->ctest_fix, p_str);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 * @param [in] dbl_param A double parameter that will be logged.
 */
static void
test_tkind_ctest_logger_recdbl_bhv(plogger_logger_t* const p_obj,\
                                   const char* const p_str,\
                                   double const dbl_param)
{
    test_tkind_ctest_fix_recdbl(&p_obj->ctest_fix, p_str, dbl_param);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 * @param [in] u16_param 
 * @param [in] char_param 
 */
static void
test_tkind_ctest_logger_recu16c_bhv(plogger_logger_t* const p_obj,\
                                    const char* const p_str,\
                                    uint16_t const u16_param,\
                                    char const char_param)
{
    test_tkind_ctest_fix_recu16c(&p_obj->ctest_fix, p_str, u16_param, char_param);
}

/**
 */
static void
test_tkind_enterstate2_setup(test_tkind_enterstate2_t* const p_obj)
{
    test_tkind_ctest_fixture_init(&ctest_sut);
}

/*** end of file ***/
