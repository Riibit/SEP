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
  public:
    static const float MIN_TEMP;
    static const float MAX_TEMP;
    static const float HOT_THRESHOLD;;
    static const float CHILLY_THRESHOLD;

    //--------------------------------------------------------------------------
    // Constructor
    EnvironmentalCondition();

    //--------------------------------------------------------------------------
    // Destructor
    ~EnvironmentalCondition();

    //--------------------------------------------------------------------------
    // The enums for cover and rank
    enum Cover {SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST};
    enum Rank {NONE, LOW, MEDIUM, HIGH};

    //--------------------------------------------------------------------------
    // Constructor for the class
    //
    // @param sky_cover The sky cover rank
    // @param precipitation The precipitation rank
    // @param temperature The temperature
    // @param wind The wind rank
    //
    EnvironmentalCondition(Cover sky_cover_, Rank precipitation_,
      float temperature_, Rank wind_);

    //--------------------------------------------------------------------------
    // Method to set sky cover rank
    //
    // @param cover The sky cover rank that is to be set
    //
    void setSkyCover(Cover cover);

    //--------------------------------------------------------------------------
    // Method to set the precipitation rank
    //
    // @param rank The precipitation rank that is to be set
    //
    void setPrecipitation(Rank rank);

    //--------------------------------------------------------------------------
    // Method to set the temperature
    //
    // @param temperature the value of the temperature that is to be set
    //
    // @return bool Return true if the temperature is in the scope
    //
    bool setTemperature(float temperature);

    //--------------------------------------------------------------------------
    // Method to set the wind rank
    //
    // @param rank The wind rank that is to be set
    //
    void setWind(Rank rank);


    //--------------------------------------------------------------------------
    // Method to get the sky cover rank
    //
    // @return EnvironmentalCondition::Cover The sky cover rank
    //
    Cover getSkyCover(void);

    //--------------------------------------------------------------------------
    // Method to get the precipitation rank
    //
    // @return EnvironmentalCondition::Rank The precipitation rank
    //
    Rank getPrecipitation(void);

    //--------------------------------------------------------------------------
    // Method to get the temperature
    //
    // @return float The temperature
    //
    float getTemperature(void);

    //--------------------------------------------------------------------------
    // Method to get the wind rank
    //
    // @return EnvironmentalCondition::Rank The wind rank
    //
    Rank getWind(void);

    //--------------------------------------------------------------------------
    // Method to find out if it is sunny
    //
    // @return bool True if it is sunny and the temperature is in the top one 
    //         third
    //
    bool isItHot();

    //--------------------------------------------------------------------------
    // Method to find out if it is rainy
    //
    // @return bool True if the precipation is medium or high and the sky cover
    //         is overcast or very overcast
    //
    bool isItRainy();

    //--------------------------------------------------------------------------
    // Method to find out if it is stormy
    //
    // @return bool True if the wind is medium or high and the sky cover is 
    //         overcast or very overcast
    //
    bool isItStormy();

    //--------------------------------------------------------------------------
    // Method to find out if it is cloudy
    //
    // @return bool True if the wind is medium or high and the sky cover is 
    //         overcast or very overcast
    //
    bool isItCloudy();

    //--------------------------------------------------------------------------
    // Method to find out if it is chilly
    //
    // @return bool True if the wind is medium or high and the sky cover is 
    //         overcast or very overcast
    //
    bool isItChilly();

    static const int MAX_COVER_INT = 3;
    static const int MAX_RANK_INT = 3;

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    EnvironmentalCondition(const EnvironmentalCondition& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    EnvironmentalCondition& operator=(const EnvironmentalCondition& original);

    //--------------------------------------------------------------------------
    // The enum variables for sky coverage, precipitation, temperature and wind
    Cover sky_cover_;
    Rank precipitation_;
    float temperature_;
    Rank wind_;
};

#endif // ENV_CON_H
