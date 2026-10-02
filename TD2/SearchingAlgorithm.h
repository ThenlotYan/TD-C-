#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include <iostream>
#include <vector>



int partition(std::vector<int>& arr, int low, int high);
void quickSort(std::vector<int>& arr, int low, int high);



class SearchingAlgorithm {
protected:
    int numberComparaison;
    int totalComparaison;
    int totalSearch;
    int averageComparaison;

    SearchingAlgorithm();

    int displaySearchResult(std::ostream& os, int result, int value);

public:
    virtual ~SearchingAlgorithm() = default;

    virtual void search(std::vector<int>& array, int value) = 0;

    int getTotalComparison() const;
};



class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();
    void search(std::vector<int>& array, int value) override;
};



class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch();
    void search(std::vector<int>& array, int value) override;
};




class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch();
    void search(std::vector<int>& array, int value) override;
};

#endif