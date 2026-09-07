/**
 * @file 
 * 
 * A Package containing test diagrams for different kinds of transitions:
 * internal, external and local.
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef TKIND_H
#define TKIND_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../umltest.h"
#    include <plogger.h>
#    include <sm.h>
#    include <event_pool.h>
#    include <stddef.h>
#    include <stdbool.h>
#    include <stdint.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The maximum number of I events stored in the I event queue.
     * @details This (and other) constant must be included by the creator inside
     * of the model. This way it provides an elastic way to specify the queue
     * size for each event.
     * A missing (unspecified explicitly in the model) constant will result in
     * the C-compiler error, since the queue buffers use these names as the
     * internal array sizes.
     * The specified size of 2 is not a random number. This is the minimum
     * recommended size of the created event queue. Although it may seem obvious
     * for a queue, the number of two
     * events in the queue means, that when one event is being processed by the
     * state machine, there will still be place for at least one new event in
     * the queue.
     * This is important for critical events, that are sent only occasionally,
     * and cannot be missed just because the event queue was filled with other
     * more frequent event types.
     */
#    define TKIND_CTEST_I_CNT 2u

    /**
     */
#    define TKIND_CTEST_O_CNT 2u

    /**
     */
#    define TKIND_CTEST_A_CNT 2u

    /**
     */
#    define TKIND_CTEST_B_CNT 2u

    /**
     */
#    define TKIND_CTEST_C_CNT 2u

    /**
     */
#    define TKIND_CTEST_F_CNT 2u

    /**
     */
#    define TKIND_CTEST_E_CNT 2u

    /**
     */
#    define TKIND_CTEST_D_CNT 2u

    /**
     */
#    define TKIND_CTEST_N_CNT 2u

    /**
     */
#    define TKIND_CTEST_H_CNT 2u

    /**
     */
#    define TKIND_CTEST_G_CNT 2u

    /**
     */
#    define TKIND_CTEST_J_CNT 2u

    /**
     */
#    define TKIND_CTEST_M_CNT 2u

    /**
     */
#    define TKIND_CTEST_K_CNT 2u

    /**
     */
#    define TKIND_CTEST_L_CNT 2u

    /**
     * @brief The size of the internal name string.
     * @details This constant is defined internally in the model as an upper
     * limit of the number of characters in the my_name property of ctest class.
     * It is automatically detected by the generator and included as a literal
     * constant in the package header.
     */
#    define TKIND_MAX_CHAR_NUM 20u

    /**
     */
#    define TKIND_PI_LITERAL_CONSTANT 3.14

    /**
     * @brief The virtual table type for the tkind_cbase1_s struct.
     */
    typedef struct tkind_cbase1_vt_s \
            tkind_cbase1_vt_t;

    /**
     * @brief The type representing the tkind_cbase1_s struct.
     */
    typedef struct tkind_cbase1_s \
            tkind_cbase1_t;

    /**
     * @brief The virtual table type for the tkind_cbase2_s struct.
     */
    typedef struct tkind_cbase2_vt_s \
            tkind_cbase2_vt_t;

    /**
     * @brief The type representing the tkind_cbase2_s struct.
     */
    typedef struct tkind_cbase2_s \
            tkind_cbase2_t;

    /**
     * @brief The type representing the tkind_sm1_s struct.
     */
    typedef struct tkind_sm1_s \
            tkind_sm1_t;

    /**
     * @brief The virtual table type for the tkind_ctest_s struct.
     */
    typedef struct tkind_ctest_vt_s \
            tkind_ctest_vt_t;

    /**
     * @brief The type representing the tkind_ctest_s struct.
     */
    typedef struct tkind_ctest_s \
            tkind_ctest_t;

    /**
     * @brief An example base class with one uint32 property.
     */
    struct tkind_cbase1_s
    {
        /**
         */
        uint32_t                        Property1;
        /**
         * @brief The pointer to the virtual table of the cbase1 class.
         */
        const tkind_cbase1_vt_t*        p_vtable;
    };

    /**
     * @brief The virtual table struct for the tkind_cbase1_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct tkind_cbase1_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         * @param [in] param1 
         */
        void (*p_setuintprop)(tkind_cbase1_t* const p_obj,\
                              uint32_t const param1);
    };

    /**
     * @brief An example base class with one float property.
     */
    struct tkind_cbase2_s
    {
        /**
         */
        float                           Property1;
        /**
         * @brief The pointer to the virtual table of the cbase2 class.
         */
        const tkind_cbase2_vt_t*        p_vtable;
    };

    /**
     * @brief The virtual table struct for the tkind_cbase2_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct tkind_cbase2_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         * @return 
         */
        float (*p_getfloatprop)(tkind_cbase2_t* const p_obj);
    };

    /**
     * @brief The enumeration of all substates of Region1 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_INITIAL1,
        /**
         */
        TKIND_SM1_STATE1,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION1_SIZE
    }tkind_sm1_region1_t;
    
    /**
     * @brief The enumeration of all substates of Region2 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region2 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_INITIAL3,
        /**
         * Only local transitions are linked with this state
         */
        TKIND_SM1_STATE3,
        /**
         */
        TKIND_SM1_STATE2,
        /**
         * Only external transitions are linked to this state
         */
        TKIND_SM1_STATE4,
        /**
         * @brief The number of all substates of Region2 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION2_SIZE
    }tkind_sm1_region2_t;
    
    /**
     * @brief The enumeration of all substates of Region3 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region3 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION3_INL,
        /**
         */
        TKIND_SM1_STATE5,
        /**
         * @brief The number of all substates of Region3 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION3_SIZE
    }tkind_sm1_region3_t;
    
    /**
     * @brief The enumeration of all substates of Region4 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region4 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION4_INL,
        /**
         */
        TKIND_SM1_STATE6,
        /**
         * @brief The number of all substates of Region4 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION4_SIZE
    }tkind_sm1_region4_t;
    
    /**
     * @brief The enumeration of all substates of Region5 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region5 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION5_INL,
        /**
         */
        TKIND_SM1_STATE7,
        /**
         */
        TKIND_SM1_STATE8,
        /**
         * @brief The number of all substates of Region5 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION5_SIZE
    }tkind_sm1_region5_t;
    
    /**
     * @brief The enumeration of all substates of Region6 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region6 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_INITIAL4,
        /**
         */
        TKIND_SM1_STATE9,
        /**
         * @brief The number of all substates of Region6 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION6_SIZE
    }tkind_sm1_region6_t;
    
    /**
     * @brief An example StateMachine implementing different kinds of
     * transitions.
     */
    struct tkind_sm1_s
    {
        /**
         * @brief The pointer to the StateMachine's context object.
         */
        tkind_ctest_t*                  p_context;
        /**
         */
        tkind_sm1_region1_t             region1;
        /**
         */
        tkind_sm1_region2_t             region2;
        /**
         */
        tkind_sm1_region3_t             region3;
        /**
         */
        tkind_sm1_region4_t             region4;
        /**
         * This region has no initial transition and allows to verify the
         * correctness of transition sequences in this case
         */
        tkind_sm1_region5_t             region5;
        /**
         */
        tkind_sm1_region6_t             region6;
        /**
         */
        bool                            b_test_condition;
    };

    /**
     * @brief The enumeration of all events handled by ctest Class.
     */
    enum tkind_ctest_evtype
    {
        /**
         */
        TKIND_CTEST_I,
        /**
         */
        TKIND_CTEST_O,
        /**
         */
        TKIND_CTEST_A,
        /**
         */
        TKIND_CTEST_B,
        /**
         */
        TKIND_CTEST_C,
        /**
         */
        TKIND_CTEST_F,
        /**
         */
        TKIND_CTEST_E,
        /**
         */
        TKIND_CTEST_D,
        /**
         */
        TKIND_CTEST_N,
        /**
         */
        TKIND_CTEST_H,
        /**
         */
        TKIND_CTEST_G,
        /**
         */
        TKIND_CTEST_J,
        /**
         */
        TKIND_CTEST_M,
        /**
         */
        TKIND_CTEST_K,
        /**
         */
        TKIND_CTEST_L,
        /**
         * @brief The number of all events handled by ctest Class.
         */
        TKIND_CTEST_EVENT_COUNT
    };
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the ctest class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the ctest class.
         */
        event_pool_t                    manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t               fifo_pool[TKIND_CTEST_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any i event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_I] object.
         */
        event_pool_size_t               i_next_events[TKIND_CTEST_I_CNT];
        /**
         * @brief The array of the events that follow any o event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_O] object.
         */
        event_pool_size_t               o_next_events[TKIND_CTEST_O_CNT];
        /**
         * @brief The array of the events that follow any a event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_A] object.
         */
        event_pool_size_t               a_next_events[TKIND_CTEST_A_CNT];
        /**
         * @brief The array of the events that follow any b event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_B] object.
         */
        event_pool_size_t               b_next_events[TKIND_CTEST_B_CNT];
        /**
         * @brief The array of the events that follow any c event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_C] object.
         */
        event_pool_size_t               c_next_events[TKIND_CTEST_C_CNT];
        /**
         * @brief The array of the events that follow any f event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_F] object.
         */
        event_pool_size_t               f_next_events[TKIND_CTEST_F_CNT];
        /**
         * @brief The array of the events that follow any e event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_E] object.
         */
        event_pool_size_t               e_next_events[TKIND_CTEST_E_CNT];
        /**
         * @brief The array of the events that follow any d event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_D] object.
         */
        event_pool_size_t               d_next_events[TKIND_CTEST_D_CNT];
        /**
         * @brief The array of the events that follow any n event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_N] object.
         */
        event_pool_size_t               n_next_events[TKIND_CTEST_N_CNT];
        /**
         * @brief The array of the events that follow any h event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_H] object.
         */
        event_pool_size_t               h_next_events[TKIND_CTEST_H_CNT];
        /**
         * @brief The array of the events that follow any g event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_G] object.
         */
        event_pool_size_t               g_next_events[TKIND_CTEST_G_CNT];
        /**
         * @brief The array of the events that follow any j event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_J] object.
         */
        event_pool_size_t               j_next_events[TKIND_CTEST_J_CNT];
        /**
         * @brief The array of the events that follow any m event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_M] object.
         */
        event_pool_size_t               m_next_events[TKIND_CTEST_M_CNT];
        /**
         * @brief The array of the events that follow any k event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_K] object.
         */
        event_pool_size_t               k_next_events[TKIND_CTEST_K_CNT];
        /**
         * @brief The array of the events that follow any l event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_L] object.
         */
        event_pool_size_t               l_next_events[TKIND_CTEST_L_CNT];
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
    }tkind_ctest_event_pool_t;
    
    /**
     * @brief This is a comment linked to the ctest type.
     */
    struct tkind_ctest_s
    {
        /**
         * @brief cbase1 base class data.
         */
        tkind_cbase1_t                  cbase1;
        /**
         * @brief cbase2 base class data.
         */
        tkind_cbase2_t                  cbase2;
        /**
         * @brief The event pool object managing all events corresponding to the
         * ctest class.
         */
        tkind_ctest_event_pool_t        event_pool;
        /**
         * @brief The instance of the sm1 state machine. 
         * @details According to UML, ctest class is the context of the sm1
         * state machine.
         */
        tkind_sm1_t                     sm1;
        /**
         */
        char                            my_name[TKIND_MAX_CHAR_NUM];
        /**
         */
        double                          pi;
        /**
         * The pointer to an object used to record the executed statemachine
         * transition comments.
         */
        plogger_logger_t*               p_logger;
    };

    /**
     * @brief The virtual table struct for the tkind_ctest_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct tkind_ctest_vt_s
    {
        /**
         * cbase1 base class virtual table.
         */
        tkind_cbase1_vt_t               cbase1;
        /**
         * cbase2 base class virtual table.
         */
        tkind_cbase2_vt_t               cbase2;
    };

    bool tkind_cbase1_init(tkind_cbase1_t* const p_obj);
    void tkind_cbase1_setuintprop(tkind_cbase1_t* const p_obj,\
                                  uint32_t const param1);
    uint32_t tkind_cbase1_getuintprop(tkind_cbase1_t* const p_obj);

    bool tkind_cbase2_init(tkind_cbase2_t* const p_obj);
    void tkind_cbase2_setfloatprop(tkind_cbase2_t* const p_obj,\
                                   float const param1);
    float tkind_cbase2_getfloatprop(tkind_cbase2_t* const p_obj);

    bool tkind_ctest_init(tkind_ctest_t* const p_obj,\
                          plogger_logger_t* const p_logger);
    bool tkind_ctest_a(tkind_ctest_t* const p_obj);
    bool tkind_ctest_b(tkind_ctest_t* const p_obj);
    bool tkind_ctest_c(tkind_ctest_t* const p_obj);
    bool tkind_ctest_d(tkind_ctest_t* const p_obj);
    bool tkind_ctest_e(tkind_ctest_t* const p_obj);
    bool tkind_ctest_f(tkind_ctest_t* const p_obj);
    bool tkind_ctest_g(tkind_ctest_t* const p_obj);
    bool tkind_ctest_h(tkind_ctest_t* const p_obj);
    bool tkind_ctest_i(tkind_ctest_t* const p_obj);
    bool tkind_ctest_j(tkind_ctest_t* const p_obj);
    bool tkind_ctest_k(tkind_ctest_t* const p_obj);
    bool tkind_ctest_l(tkind_ctest_t* const p_obj);
    bool tkind_ctest_m(tkind_ctest_t* const p_obj);
    bool tkind_ctest_n(tkind_ctest_t* const p_obj);
    bool tkind_ctest_o(tkind_ctest_t* const p_obj);
    bool tkind_ctest_fetch_event(tkind_ctest_t* const p_obj);
    bool tkind_ctest_dispatch_event(tkind_ctest_t* const p_obj);
    bool tkind_ctest_release_event(tkind_ctest_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* TKIND_H */

/*** end of file ***/
