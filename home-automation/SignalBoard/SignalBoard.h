#pragma once

namespace board
{
  
}

class SignalBoard
{
  private:
    bool RED = false;
    bool GREEN = false;
    bool BLUE = false;

  public:
    virtual void setup();
    virtual void alarm();
};

/**
 * Rows of X switches (devices) and Y signals
 * RED: Error
 * Green: Working
 * Blue: Functional
 * 
 * WaterLevel: R|G|B
 * Water Motor: R|G|B
 * Doors Reeds: R|G|B
 * LDR Alarm: R|G|B
 * LDR Detection: R|G|B
 */
