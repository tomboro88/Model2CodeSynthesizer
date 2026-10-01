/**
 * @file 
 * 
 * @brief Package with standalone state machine not having it's parent context
 * class.
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef STANDALONE_H
#define STANDALONE_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../umltest.h"
#    include <sm.h>
#    include <event_pool.h>
#    include <stddef.h>
#    include <stdbool.h>
//Start of user code includes bottom
//End of user code

    /**
     */
#    define STANDALONE_SM_A_CNT 2u

    /**
     */
#    define STANDALONE_SM_B_CNT 2u

    /**
     * @brief The type representing the standalone_sm_s struct.
     */
    typedef struct standalone_sm_s \
            standalone_sm_t;

    /**
     * @brief The enumeration of all substates of Region1 Region of sm
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of sm StateMachine.
         */
        STANDALONE_SM_INITIAL1,
        /**
         */
        STANDALONE_SM_STATE2,
        /**
         */
        STANDALONE_SM_STATE4,
        /**
         */
        STANDALONE_SM_STATE5,
        /**
         * @brief The number of all substates of Region1 Region of sm
         * StateMachine.
         */
        STANDALONE_SM_REGION1_SIZE
    }standalone_sm_region1_t;
    
    /**
     * @brief The enumeration of all events handled by sm Class.
     */
    enum standalone_sm_evtype
    {
        /**
         */
        STANDALONE_SM_A,
        /**
         */
        STANDALONE_SM_B,
        /**
         * @brief The number of all events handled by sm Class.
         */
        STANDALONE_SM_EVENT_COUNT
    };
    
    /**
     * @brief The type used to store the parameters passed to the b call event.
     */
    typedef struct{
        /**
         */
        bool                            b;
    }standalone_sm_b_t;
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the sm class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the sm class.
         */
        event_pool_t                    manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t               fifo_pool[STANDALONE_SM_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any a event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[STANDALONE_SM_A] object.
         */
        event_pool_size_t               a_next_events[STANDALONE_SM_A_CNT];
        /**
         * @brief The array of the events that follow any b event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[STANDALONE_SM_B] object.
         */
        event_pool_size_t               b_next_events[STANDALONE_SM_B_CNT];
        /**
         * @brief The array of the arguments passed to the corresponding b event
         * in the event pool sequence.
         */
        standalone_sm_b_t               b_args[STANDALONE_SM_B_CNT];
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
    }standalone_sm_event_pool_t;
    
    /**
     */
    struct standalone_sm_s
    {
        /**
         */
        standalone_sm_region1_t         region1;
        /**
         * @brief The event pool object managing all events corresponding to the
         * sm class.
         */
        standalone_sm_event_pool_t      event_pool;
    };

    bool standalone_sm_a(standalone_sm_t* const p_obj);
    bool standalone_sm_b(standalone_sm_t* const p_obj, bool const b);
    bool standalone_sm_init(standalone_sm_t* const p_obj);
    bool standalone_sm_fetch_event(standalone_sm_t* const p_obj);
    bool standalone_sm_dispatch_event(standalone_sm_t* const p_obj);
    bool standalone_sm_release_event(standalone_sm_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* STANDALONE_H */

/*** end of file ***/
