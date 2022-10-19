#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <vector>




class Drink{
public:
    /* The constructor of the Drink. */
    Drink(){
        _name="";
        _sweetness_level=-1;
    }
    Drink(std::string name, double sweetness_level){
        if(sweetness_level < 0 || sweetness_level > 1  || name.empty() || name.length() <= 4){
            throw std::string("error");
        }
        _sweetness_level=sweetness_level;
        _name=name;
    }
    /* The destructor of the Drink. */
    ~Drink(){

    }
    /* Return the name of drink. */
    std::string getName(){
        if(_name.empty() || _name.size()<=4){
            throw std::string("Name is empty");
        }
        return _name;
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if(_sweetness_level==-1){
            // std::cout << "_sweetness_level error" << std::endl;
            throw std::string("_sweetness_level error | No set");
        }else if(_sweetness_level < 0 || _sweetness_level >1){
            // std::cout << "_sweetness_level error" << std::endl;
            throw std::string("_sweetness_level error | out of range");
        }
        return _sweetness_level;
    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping){
        _topping.push_back(topping);
    }
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index){
        if(index < _topping.size())
            return _topping[index];
        throw std::string("getToppingByIndex error");
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return _topping.size();
    }
private:
    /* Put some attribute on here if necessary. */
    std::string _name;
    std::vector<std::string> _topping;
    double _sweetness_level;
};

#endif
