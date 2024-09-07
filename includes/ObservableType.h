#ifndef __OBSERVABLETYPE_H__
#define __BOSERVABLETYPE_H__

template <class U> 
class ObservableType
{
    public: 
        ObservableType(U value){
            this->value = value;
        }; 

        ObservableType& operator=(U value){
            this->value = value; 
            this->isChangedFlg = 1; 
            return *this; 
        }

        bool isChanged(){
            return this->isChangedFlg; 
        }
        
        void operator+=(U value){
            this->value += value; 
            this->isChangedFlg = 1; 
        }

        void operator-=(U value){
            this->value -= value; 
            this->isChangedFlg = 1; 
        }
        U getValue(){
            return this->value; 
        }
        void disableState(){
            this->isChangedFlg = 0; 
        }

    private: 
        U value; 
        bool isChangedFlg = 0; 

};
 
#endif