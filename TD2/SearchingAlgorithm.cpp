#include <iostream>
#include <vector>
#include <math.h>


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


class SearchingAlgorithm {
    protected:
    int numberComparaison;
    int totalComparaison;
    int totalSearch;
    int averageComparaison;

    SearchingAlgorithm(): numberComparaison(0), totalComparaison(0), totalSearch(0), averageComparaison(0){}

    virtual void search(std::vector<int> &array, int value) = 0;


    //la fonction displaySearchResult doit calculer le totalComparaison et l'averageComparaison à chaque recherche effectuée. Elle doit également afficher le résultat de la recherche.
    int displaySearchResult(std::ostream& os, int result, int value) {
        totalSearch++;
        totalComparaison += numberComparaison;
        averageComparaison = totalComparaison / totalSearch;

        if (result != -1) {
            os << "Valeur " << value << " trouvée à l'index : " << result << std::endl;
        } else {
            os << "Valeur " << value << " non trouvée dans le tableau." << std::endl;
        }
        os << "Nombre de comparaisons pour cette recherche : " << numberComparaison << std::endl;
        os << "Nombre total de comparaisons : " << totalComparaison << std::endl;
        os << "Nombre total de recherches effectuées : " << totalSearch << std::endl;
        os << "Nombre moyen de comparaisons par recherche : " << averageComparaison << std::endl;

        numberComparaison = 0;

        return result;
    }

    int getTotalComparison(){
        return totalComparaison;
    }
    

};


class LinearSearch : public SearchingAlgorithm{
    public:
    LinearSearch():SearchingAlgorithm(){}

    void search(std::vector<int> &array, int value){
        for(int i = 0; i< array.size(); i++){
            numberComparaison++;
            if(array[i] == value){
                displaySearchResult(std::cout, i, value);
                return;
            }
        }
        displaySearchResult(std::cout, -1, value);
    }
};


class JumpSearch: public SearchingAlgorithm{
    public:
    JumpSearch():SearchingAlgorithm(){}


    void search(std::vector<int> &array, int value){
        quickSort(array, 0, array.size() - 1);

        int n = array.size();
        int step = sqrt(n);
        int prev = 0;

        while (array[std::min(step, n) - 1] < value) {
            numberComparaison++;
            prev = step;
            step += sqrt(n);
            if (prev >= n) {
                displaySearchResult(std::cout, -1, value);
                return;
            }
        }

        while (array[prev] < value) {
            numberComparaison++;
            prev++;
            if (prev == std::min(step, n)) {
                displaySearchResult(std::cout, -1, value);
                return;
            }
        }

        if (array[prev] == value) {
            numberComparaison++;
            displaySearchResult(std::cout, prev, value);
            return;
        }

        displaySearchResult(std::cout, -1, value);

    }
};

class BinarySearch: public SearchingAlgorithm{
    public:
    BinarySearch(): SearchingAlgorithm(){}

    void search(std::vector<int> &array, int value){
        quickSort(array, 0, array.size() - 1);

        int left = 0;
        int right = array.size() - 1;

        while (left <= right) {
            numberComparaison++;
            int mid = left + (right - left) / 2;

            if (array[mid] == value) {
                displaySearchResult(std::cout, mid, value);
                return;
            }

            if (array[mid] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        displaySearchResult(std::cout, -1, value);
    }



};
