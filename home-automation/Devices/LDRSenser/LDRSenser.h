class LDRSenser
{
  private:
    int pin;

  public :
    LDRSenser(int pin);
    
    void setup();
    int value();

};