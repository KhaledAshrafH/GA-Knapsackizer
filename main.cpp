#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#define endl '\n'
#define ll long long
using namespace std;

const int populationSize = 1000, numOfIterations = 15;
const double Pc = 0.8, Pm = 0.02;
int cnt=0;

class Chromosome {
private:
    ll capacity=0;
    ll numOfItems{};
    double probability;
    ll sumOfValues=0,sumOfWeights=0;
    int itemNum;
public:
    vector<bool> genes;
    Chromosome() {
        itemNum=++cnt;
    }

    virtual ~Chromosome() = default;

    Chromosome(long long int numOfItems, const vector<bool> &genes, long long int sumOfValues,
               long long int sumOfWeights, long long int capacity) : numOfItems(numOfItems), genes(genes), sumOfValues(sumOfValues),
                                                                     sumOfWeights(sumOfWeights), capacity(capacity) {}

    void setItems(ll n,ll c) {
        this->capacity=c;
        this->numOfItems=n;
        genes.resize(this->numOfItems);
        for(int i=0;i<this->numOfItems;i++)
            genes[i]=false;

    }


    void calcFitness(const vector<pair<ll,ll>>& items){
        sumOfValues=0,sumOfWeights=0;
        for(auto i=0;i<items.size();i++){
            if(genes[i]){
                sumOfWeights+=items[i].first;
                sumOfValues+=items[i].second;
            }
        }
        if(sumOfWeights>capacity) {
            sumOfValues=-1;
        }
    }

    long long int getSumOfValues() const {
        return sumOfValues;
    }

    long long int getSumOfWeights() const {
        return sumOfWeights;
    }

    double getProbability() const {
        return probability;
    }

    void setProbability(double probability) {
        Chromosome::probability = probability;
    }

    int getItemNum() const {
        return itemNum;
    }

    void setItemNum(int itemNum) {
        Chromosome::itemNum = itemNum;
    }
};

bool compareProb(const Chromosome& c1,const Chromosome& c2){
    return c1.getProbability()<c2.getProbability();
}

bool compareVal(const Chromosome& c1,const Chromosome& c2){
    return c1.getSumOfValues()>c2.getSumOfValues();
}

class GA{
private:
    vector<Chromosome>* solutions;
public:
    GA(vector<Chromosome>& solutions) {
        this->solutions=&solutions;
    }

    void initializePopulation(){
        for(auto & solution : *solutions){
            for(auto && gene : solution.genes){
                gene=rand()%2;
            }
        }
    }

    void rouletteWheel(){
        auto & sol=*solutions;

        vector<Chromosome> res(sol.size());
        map<double,int> probabilityToIndex;
        double sumFitness=0.0,TEMP;
        for(auto & solution : *solutions){
            sumFitness+=solution.getSumOfValues();
        }

        TEMP=sol[0].getSumOfValues()/sumFitness;
        sol[0].setProbability(TEMP);
        probabilityToIndex[TEMP]=0;
        for(auto i=1;i<sol.size();i++){
            TEMP=(sol[i].getSumOfValues()/sumFitness)+sol[i-1].getProbability();
            sol[i].setProbability(TEMP);
            probabilityToIndex[TEMP]=i;
        }
        sort(sol.begin(),sol.end(), compareProb);
        for (int i = 0; i < populationSize; i++) {
            double random_key = ((double) rand() / (RAND_MAX));
            auto iter = probabilityToIndex.upper_bound(random_key-0.1);
            if (iter != probabilityToIndex.begin())
                iter--;
            res[i]=sol[iter->second];
        }
        for (auto i=0;i<populationSize;i++) {
            sol[i]=res[i];
        }

        sort(sol.begin(),sol.end(),compareVal);
    }
    void crossOver(){
        auto & sol=*solutions;
        for(int i=0;i<populationSize;i++){
            for(int j=i+1;j<populationSize;j++){
                double randNum=((double) rand() / (RAND_MAX));
                if(randNum<Pc){
                    int randNumIdx=rand()%(sol[i].genes.size()-1);
                    for(int k=randNumIdx;k<sol[i].genes.size();k++){
                        swap(sol[i].genes[k],sol[j].genes[k]);
                    }
                }
            }
        }
    }
    void mutation(){
        auto & sol=*solutions;
        for(int i=0;i<populationSize;i++){
            for(auto && gene : sol[i].genes){
                double randNum=((double) rand() / (RAND_MAX));
                if(randNum<Pm)
                    gene=!gene;
            }
        }
    }

};


int main() {
    srand(time(nullptr));

    ll numOftestCases,numOfItems,capacity,iterationsSize;cin>>numOftestCases;
    while(numOftestCases--){
        iterationsSize=numOfIterations;
        cin>>capacity>>numOfItems;
        vector<pair<ll,ll>> items(numOfItems);
        for(auto i=0;i<numOfItems;i++) cin>>items[i].first>>items[i].second;
        vector<Chromosome> solutions(populationSize);
        for (int i = 0; i < populationSize; i++)
            solutions[i].setItems(numOfItems,capacity);

        GA geneticAlgorithm(solutions);

        //First Step (Initialize Pool Of Solutions)
        geneticAlgorithm.initializePopulation();

        while(iterationsSize--){
            //Second Step (Individual Evaluation)
            for (int i = 0; i < populationSize; i++)
                solutions[i].calcFitness(items);

            sort(solutions.begin(),solutions.end(),compareVal);
            //Third Step (Selection)
            geneticAlgorithm.rouletteWheel();

            //Fourth Step (Crossover)
            geneticAlgorithm.crossOver();

            //Fourth Step (Mutation)
            geneticAlgorithm.mutation();

            //Fifth Step (Reproduction)
        }
        sort(solutions.begin(),solutions.end(),compareVal);
        cout<<solutions[0].getSumOfValues()<<endl;
    }
    return 0;
}
