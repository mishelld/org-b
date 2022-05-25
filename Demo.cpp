/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
  OrgChart organization;

  try{
		 organization.add_sub("EARTH", "SEA");    
	}catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
  organization.add_root("EARTH")
      .add_sub("EARTH", "SEA")         
      .add_sub("EARTH", "LAND")         
      .add_sub("SEA", "FISH")   
      .add_sub("FISH", "SHARK")   
      .add_sub("FISH", "WHALE")   
      .add_sub("FISH", "DOLPHIN")                           
      .add_sub("LAND", "JUNGLE")
      .add_sub("JUNGLE", "LION")
      .add_sub("JUNGLE", "BEAR")
      .add_sub("JUNGLE", "ELEPHANT")
      .add_sub("JUNGLE", "GORILLA")
      .add_sub("LAND", "MOUNTAIN") 
      .add_sub("LAND", "DESERT")    
      .add_sub("DESERT", "CAMELS")
      .add_sub("DESERT", "SCORPION")    
      .add_sub("DESERT", "SNAKE");      
   


  cout << organization << endl;  
      
  /*
father:EARTH|children:,SEA,LAND|
father:SEA|children:,FISH|
father:LAND|children:,JUNGLE,MOUNTAIN,DESERT|
father:FISH|children:,SHARK,WHALE,DOLPHIN|
father:SHARK|children:no children|
father:WHALE|children:no children|
father:DOLPHIN|children:no children|
father:JUNGLE|children:,LION,BEAR,ELEPHANT,GORILLA|
father:LION|children:no children|
father:BEAR|children:no children|
father:ELEPHANT|children:no children|
father:GORILLA|children:no children|
father:MOUNTAIN|children:no children|
father:DESERT|children:,CAMELS,SCORPION,SNAKE|
father:CAMELS|children:no children|
father:SCORPION|children:no children|
father:SNAKE|children:no children|
  */

  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: EARTH SEA LAND FISH JUNGLE MOUNTAIN DESERT SHARK WHALE DOLPHIN LION BEAR ELEPHANT GORILLA CAMELS SCORPION SNAKE 
  cout << endl;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: SHARK WHALE DOLPHIN FISH JUNGLE MOUNTAIN DESERT SEA LAND EARTH 
    cout << endl;

  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: EARTH SEA FISH SHARK WHALE DOLPHIN LAND JUNGLE LION BEAR ELEPHANT GORILLA MOUNTAIN DESERT CAMELS SCORPION SNAKE 
  cout << endl;

  for (auto element : organization)
  { 
    cout << element << " " ;
  } // prints: EARTH SEA LAND FISH JUNGLE MOUNTAIN DESERT SHARK WHALE DOLPHIN LION BEAR ELEPHANT GORILLA CAMELS SCORPION SNAKE 

  cout << endl;

  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 5 3 4 4 6 8 6 5 5 7 4 4 8 7 6 8 5 
    cout << endl;


  OrgChart org;


  try{
		  org.add_sub("root", "branch1");
    
	}catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
org.add_root("root")
  .add_sub("root", "branch1")
  .add_sub("root", "branch2")
  .add_sub("root", "branch3")
  .add_sub("branch1", "leaf1")
  .add_sub("branch1", "leaf2")
  .add_sub("branch1", "leaf3")
  .add_sub("branch2", "leaf4")
  .add_sub("branch2", "leaf5")
  .add_sub("branch2", "leaf6")
  .add_sub("branch3", "leaf7")
  .add_sub("branch3", "leaf8")
  .add_sub("branch3", "leaf9");
  cout << org << endl;


  /*

father:root|children:,branch1,branch2,branch3|
father:branch1|children:,leaf1,leaf2,leaf3|
father:branch2|children:,leaf4,leaf5,leaf6|
father:branch3|children:,leaf7,leaf8,leaf9|
father:leaf1|children:no children|
father:leaf2|children:no children|
father:leaf3|children:no children|
father:leaf4|children:no children|
father:leaf5|children:no children|
father:leaf6|children:no children|
father:leaf7|children:no children|
father:leaf8|children:no children|
father:leaf9|children:no children|
  */

  for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: root branch1 branch2 branch3 leaf1 leaf2 leaf3 leaf4 leaf5 leaf6 leaf7 leaf8 leaf9 
  cout << endl;
  for (auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: leaf1 leaf2 leaf3 leaf4 leaf5 leaf6 leaf7 leaf8 leaf9 branch1 branch2 branch3 root  
    cout << endl;

  for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: root branch1 leaf1 leaf2 leaf3 branch2 leaf4 leaf5 leaf6 branch3 leaf7 leaf8 leaf9 
  cout << endl;

  for (auto element : org)
  { 
    cout << element << " " ;
  } // prints: root branch1 branch2 branch3 leaf1 leaf2 leaf3 leaf4 leaf5 leaf6 leaf7 leaf8 leaf9 

  cout << endl;

  // demonstrate the arrow operator:
  for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 4 7 7 7 5 5 5 5 5 5 5 5 5 
    cout << endl;


  OrgChart temp;
   try{
		  temp.add_sub("universe", "earth");
    
	}catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
  temp.add_root("universe")
  .add_sub("universe", "earth")
  .add_sub("universe", "sun")
  .add_sub("universe", "moon")
  .add_sub("earth", "countries")
  .add_sub("countries", "cities")
  .add_sub("moon", "rocks");

/*
father:universe|children:,earth,sun,moon|
father:earth|children:,countries|
father:sun|children:no children|
father:moon|children:,rocks|
father:countries|children:,cities|
father:cities|children:no children|
father:rocks|children:no children|
*/
  cout << temp << endl;
  for (auto it = temp.begin_level_order(); it != temp.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: universe earth sun moon countries rocks cities 
  for (auto it = temp.begin_reverse_order(); it != temp.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: cities countries rocks earth sun moon universe 
    cout << endl;

  for (auto it=temp.begin_preorder(); it!=temp.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: universe earth countries cities sun moon rocks 
  cout << endl;

  for (auto element : temp)
  { 
    cout << element << " " ;
  } // prints: universe earth sun moon countries rocks cities 

  cout << endl;

  // demonstrate the arrow operator:
  for (auto it = temp.begin_level_order(); it != temp.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 8 5 3 4 9 5 6 
    cout << endl;

}
