//------------------------------------------------------------------------------
// EnvironmentalCondition.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef ENV_CON_H
#define ENV_CON_H

//------------------------------------------------------------------------------
// The class that contains all environmental conditions
//
class EnvironmentalCondition 
{
  private:
    enum Cover {SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST};
    enum Rank {NONE, LOW, MEDIUM, HIGH};
    Cover sky_cover_;
    Rank precipitation_;
    float temperature_;
    Rank wind_;
    bool isItHot();
    bool isItRainy();
    bool isItStormy();
    EnvironmentalCondition(Cover sky_cover_, Rank precipitation_,
    float temperature_, Rank wind_);
  public:
    void setSkyCover(Cover cover);
    void setPrecipitation(Rank rank);
    void setTemperature(float temperature);
    void setWind(Rank rank);
    Cover getSkyCover(void);
    Rank getPrecipitation(void);
    float getTemperature(void);
    Rank getWind(void);
};

#endif // ENV_CON_H
