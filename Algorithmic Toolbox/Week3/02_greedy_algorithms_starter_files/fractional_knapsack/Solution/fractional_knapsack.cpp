#include <iostream>
#include <vector>

using std::vector;

int get_max_index(double mpu[], int n)
{
	int max_value = 0;
	int max_index = 0;
	
	for(int i =0; i<n; i++)
	{
		if(mpu[i]>max_value){
			max_value = mpu[i];
			max_index = i;
		}
	}
	return max_index;
}

double get_optimal_value(int capacity, vector<double> weights, vector<double> values, int n) {
  double value = 0.0;
  double mpu[n] = {0.0};
  double remWeight = capacity;
  //std::cout<<"Rem weight "<<remWeight<<std::endl;
  for(int i=0;i<n;i++){
  		mpu[i] = (double)values[i]/(double)weights[i];
  		//std::cout<<mpu[i]<<" ";
	}
	//std::cout<<std::endl;
  while(remWeight>0)
  {
  	int max_index = 0;
  	max_index = get_max_index(mpu,n);
  	//std::cout<<max_index<<std::endl;
  	if(weights[max_index] <= remWeight){
	  //	std::cout<<weights[max_index]<<std::endl;
		//std::cout<<values[max_index]<<std::endl;
  		value += values[max_index];
  		//std::cout<<value<<std::endl;
  		remWeight -= weights[max_index];
  		//std::cout<<"Rem weight "<<remWeight<<std::endl;
	
  	}
	  
	else if(weights[max_index] > remWeight){
		//std::cout<<"I am in else :( ";
  		double fraction = values[max_index]/weights[max_index];
  		value += remWeight*fraction;
  		//std::cout<<values[max_index]<<std::endl;
  		break;
	  }
	mpu[max_index] = 0;	  
	values[max_index] = 0;
	//weights[max_index] = 0;	
  }
  
  return value;

  //return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values,n);
  //std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
