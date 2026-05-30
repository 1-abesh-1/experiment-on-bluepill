          ┌─────────────────────────────┐
          │ 1. Enable Timer Clock (RCC) │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 2. Configure GPIO (AF mode) │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 3. Set Timer Base           │
          │ PSC = prescaler             │
          │ ARR = period                │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 4. Set PWM Mode             │
          │ CCMR → OCxM = 110 (PWM1)    │
          │ Enable preload (OCxPE)      │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 5. Set Duty Cycle           │
          │ CCRx = compare value        │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 6. Enable Channel Output    │
          │ CCER → enable CHx           │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 7. Enable Auto-Reload Preload│
          │ CR1 → ARPE = 1              │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 8. Force Update Event       │
          │ EGR → UG = 1               │
          │ (sync registers)            │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 9. Start Timer              │
          │ CR1 → CEN = 1               │
          └────────────┬────────────────┘
                       │
                       v
          ┌─────────────────────────────┐
          │ 10. PWM Running Loop        │
          │ CNT counts: 0 → ARR         │
          │ Compare CNT vs CCRx         │
          │ Output toggles automatically │
          └─────────────────────────────┘
