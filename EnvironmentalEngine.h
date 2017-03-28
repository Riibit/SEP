//------------------------------------------------------------------------------
// EnvironmentalEngine.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinić 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef ENV_ENG_H
#define ENV_ENG_H
class EnvironmentalCondition;

//------------------------------------------------------------------------------
// The class that contains the environmental engine
//
class EnvironmentalEngine 
{
private:
  Cover sky_cover_rng;
  Rank precipitation_rng;
  float temperature_rng;
  Rank wind_rng;
public:
  EnvironmentalCondition createCondition();	
};

#endif // ENV_ENG_H
