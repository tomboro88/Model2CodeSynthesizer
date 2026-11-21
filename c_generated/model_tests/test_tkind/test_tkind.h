/**
 * @file 
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef TEST_TKIND_H
#define TEST_TKIND_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../tests.h"
#    include <Tkind.h>
#    include <plogger.h>
#    include <sm.h>
#    include <event_pool.h>
#    include <stddef.h>
#    include <stdbool.h>
#    include <stdint.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The type representing the test_tkind_a_state2_sm_s struct.
     */
    typedef struct test_tkind_a_state2_sm_s \
            test_tkind_a_state2_sm_t;

    /**
     * @brief The type representing the test_tkind_ctest_logger_s struct.
     */
    typedef struct test_tkind_ctest_logger_s \
            test_tkind_ctest_logger_t;

    /**
     * @brief The virtual table type for the test_tkind_ctest_fixture_s struct.
     */
    typedef struct test_tkind_ctest_fixture_vt_s \
            test_tkind_ctest_fixture_vt_t;

    /**
     * @brief The type representing the test_tkind_ctest_fixture_s struct.
     */
    typedef struct test_tkind_ctest_fixture_s \
            test_tkind_ctest_fixture_t;

    /**
     * @brief The enumeration of all substates of Region1 Region of a_state2_sm
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of a_state2_sm
         * StateMachine.
         */
        TEST_TKIND_A_STATE2_SM_INITIAL2,
        /**
         */
        TEST_TKIND_A_STATE2_SM_STATE10,
        /**
         * @brief The number of all substates of Region1 Region of a_state2_sm
         * StateMachine.
         */
        TEST_TKIND_A_STATE2_SM_REGION1_SIZE
    }test_tkind_a_state2_sm_region1_t;
    
    #error The a_state2_sm state machine contains more than one region named \
           Region1. Please check your model.
    /**
     * @brief The enumeration of all substates of Region1 Region of a_state2_sm
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of a_state2_sm
         * StateMachine.
         */
        TEST_TKIND_A_STATE2_SM_INITIAL1,
        /**
         */
        TEST_TKIND_A_STATE2_SM_EFFECT_BHV,
        /**
         */
        TEST_TKIND_A_STATE2_SM_EXIT_BHV,
        /**
         */
        TEST_TKIND_A_STATE2_SM_INIT,
        /**
         */
        TEST_TKIND_A_STATE2_SM_ENTRY_BHV,
        /**
         * @brief The number of all substates of Region1 Region of a_state2_sm
         * StateMachine.
         */
        TEST_TKIND_A_STATE2_SM_REGION1_SIZE
    }test_tkind_a_state2_sm_region1_t;
    
    /**
     */
    struct test_tkind_a_state2_sm_s
    {
        /**
         * @brief The pointer to the StateMachine's context object.
         */
        test_tkind_ctest_fixture_t*     p_context;
        /**
         */
        test_tkind_a_state2_sm_region1_t \
                                        region1;
        /**
         */
        test_tkind_a_state2_sm_region1_t \
                                        region1;
    };

    /**
     */
    struct test_tkind_ctest_logger_s
    {
        /**
         */
        test_tkind_ctest_fixture_t*     ctest_fix;
    };
#error No constructor was defined for the ctest_logger class. 

    /**
     * @brief The enumeration of all events handled by ctest_fixture Class.
     */
    enum test_tkind_ctest_fixture_evtype
    {
        /**
         */
        TEST_TKIND_CTEST_FIXTURE_REC_CALL,
        /**
         * @brief The number of all events handled by ctest_fixture Class.
         */
        TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT
    };
    
    /**
     * @brief The type used to store the parameters passed to the rec call
     * event.
     */
    typedef struct{
        /**
         */
        char                            p_str;
    }test_tkind_ctest_fixture_rec_call_t;
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the ctest_fixture class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the ctest_fixture class.
         */
        event_pool_t                    manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t               fifo_pool\
                                        [TEST_TKIND_CTEST_FIXTURE_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any rec_call event in the
         * event pool sequence.
         * @details It is referenced by the
         * fifo_pool[TEST_TKIND_CTEST_FIXTURE_REC_CALL] object.
         */
        event_pool_size_t               rec_call_next_events\
                                        [TEST_TKIND_CTEST_FIXTURE_REC_CALL_CNT];
        /**
         * @brief The array of the arguments passed to the corresponding
         * rec_call event in the event pool sequence.
         */
        test_tkind_ctest_fixture_rec_call_t \
                                        rec_call_args\
                                        [TEST_TKIND_CTEST_FIXTURE_REC_CALL_CNT];
        /**
         * @brief The marker that stores the processing status of the event at
         * the 'first' position.
         * @details It is used to prevent processing of the same event multiple
         * times, and from removing unprocessed events. Moreover it can be used
         * to handle event deferring.
         */
        sm_event_status_t               event_proc_status;
        /**
         * @brief Stores the location of the event that is currently being
         * processed.
         */
        event_pool_locator_t            fetched_event;
    }test_tkind_ctest_fixture_event_pool_t;
    
    /**
     */
    struct test_tkind_ctest_fixture_s
    {
        /**
         * @brief ctest base class data.
         */
        tkind_ctest_t                   ctest;
        /**
         * @brief The event pool object managing all events corresponding to the
         * ctest_fixture class.
         */
        test_tkind_ctest_fixture_event_pool_t \
                                        event_pool;
        /**
         * @brief The instance of the a_state2_sm state machine. 
         * @details According to UML, ctest_fixture class is the context of the
         * a_state2_sm state machine.
         */
        test_tkind_a_state2_sm_t        a_state2_sm;
        /**
         */
        test_tkind_ctest_logger_t       ctest_logger;
        /**
         */
        bool                            b_is_completed;
    };

    /**
     * @brief The virtual table struct for the test_tkind_ctest_fixture_s
     * struct. Contains pointers to all virtual methods of the class.
     */
    struct test_tkind_ctest_fixture_vt_s
    {
        /**
         * ctest base class virtual table.
         */
        tkind_ctest_vt_t                ctest;
    };

    bool test_tkind_ctest_fixture_init(test_tkind_ctest_fixture_t* const p_obj);
    bool test_tkind_ctest_fixture_rec(test_tkind_ctest_fixture_t* const p_obj,\
                                      char const p_str);
    bool test_tkind_ctest_fixture_recdbl(test_tkind_ctest_fixture_t* \
                                         /**/const p_obj, char const p_str,\
                                         double const dbl_param);
    bool test_tkind_ctest_fixture_recu16c(test_tkind_ctest_fixture_t* \
                                          /**/const p_obj, char const p_str,\
                                          uint16_t const u16_param,\
                                          char const char_param);
    void test_tkind_ctest_fixture_drain_events(test_tkind_ctest_fixture_t* \
                                               /**/const p_obj);
    bool test_tkind_ctest_fixture_fetch_event(test_tkind_ctest_fixture_t* \
                                              /**/const p_obj);
    bool test_tkind_ctest_fixture_dispatch_event(test_tkind_ctest_fixture_t* \
                                                 /**/const p_obj);
    bool test_tkind_ctest_fixture_release_event(test_tkind_ctest_fixture_t* \
                                                /**/const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* TEST_TKIND_H */

/*** end of file ***/
