#include<bits/stdc++.h>
using namespace std;

class sortingStrategy{
public:
virtual void sort(vector<int>&arr)=0;
};

class BubbleSort : public sortingStrategy{
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Bubble Sort algorithm
    }
};

class QuickSort : public sortingStrategy{
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Quick Sort algorithm
    }
};

class sortingContext{
private:
sortingStrategy * strategy;
public:

void setStrategy(sortingStrategy * newstrategy){
    strategy=newstrategy;
}

void execute_strategy(vector<int>& arr){
    strategy->sort(arr);
}
};

int main(){
vector<int> data = { 5, 2, 7, 1, 9 };

BubbleSort bubble;
QuickSort quick;

sortingContext strategy;

strategy.setStrategy(&bubble);
strategy.execute_strategy(data);


}