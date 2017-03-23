//------------------------------------------------------------------------------
// EnvironmentalCondition.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 143****
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <iostream>


class EnvironmentalCondition 
{
  enum Cover {SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST};
  enum Rank {NONE, LOW, MEDIUM, HIGH};
    Cover sky_cover_;
    Rank precipitation_;
    float temperature_;
    Rank wind_;
  public:
    bool isItHot();
    bool isItRainy();
    bool isItStormy();
};

bool EnvironmentalCondition::isItHot()
{
  if (sky_cover_ == SUNNY && temperature_ > (25/3+10))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool EnvironmentalCondition::isItRainy()
{
  if ((precipitation_ == MEDIUM || precipitation_ == HIGH)
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  } 
}

bool EnvironmentalCondition::isItStormy()
{
  if ((wind_ == MEDIUM || wind_ == HIGH) 
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main ()
{
  std::cout << "DEBUG" << std::endl;
  return 0;
}