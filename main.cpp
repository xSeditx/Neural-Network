#include<iostream>
#include <time.h>

#define NUM_INPUTS 3
#define NUM_HIDDEN 4
#define NUM_OUTPUTS 1
#define NUM_SAMPLES 5
#define L_C .01
struct NEURON{
	double VALUE;
	double DELTA;
};


double INPUT_WEIGHTS [NUM_INPUTS][NUM_HIDDEN ] = {0};
double HIDDEN_WEIGHTS[NUM_HIDDEN][NUM_OUTPUTS] = {0};


int _FORWARD_PROPAGATION();
int _BACK_PROPAGATION();


double Sig(double x);
void _INIT();
void _TRAINER_INIT();

NEURON INPUTS [NUM_INPUTS ] = {0},
	   HIDDEN [NUM_HIDDEN ] = {0},
	   OUTPUT [NUM_OUTPUTS] = {0};

double TRAINING_DATA_IN[8][NUM_INPUTS] = {};
double TRAINING_DATA_OUT[9]= {0};


using namespace std;


int TRAINING_SET = 0;


void main()
{
	srand(time(NULL));
	_INIT();
	while(1){
		for (int count = 0;count < 10000;count ++){
	_FORWARD_PROPAGATION();

    _BACK_PROPAGATION();
	}
	for(int i = 0; i< NUM_INPUTS;i++){
		for(int h=0;h<NUM_HIDDEN;h++){
			cout << INPUT_WEIGHTS[i][h] << " : " << endl;
	}
		cout <<"___________________________"<< endl;
	}
		
	for(int h = 0;h<NUM_HIDDEN;h++){
		for(int o=0;o<NUM_OUTPUTS;o++){
			cout << HIDDEN_WEIGHTS[h][o]  << " : "<< endl;
		}
		cout <<"_____________"<< endl;
	}

	for (int i = 0;i < NUM_INPUTS ;i++)  cout <<"INPUT:"<< i<<" "<<INPUTS[i].VALUE << endl;
	for (int h = 0;h < NUM_HIDDEN ;h++)  cout <<"HIDDEN: "<< h <<" "<<HIDDEN[h].VALUE << endl;
	for (int o = 0;o < NUM_OUTPUTS;o++)  cout <<"OUTPUT:"<< o <<" "<<OUTPUT[o].VALUE << endl;
	cout << "Expected :" << TRAINING_DATA_OUT[TRAINING_SET] << endl;
	system("PAUSE");
	}
return;
}




void _INIT()
{
	for(int i = 0;i<NUM_INPUTS;i++){
		for(int h=0;h<NUM_HIDDEN;h++)
			INPUT_WEIGHTS[i][h] = (((rand()%200) -1.0f) / 100)-1.0f;
	}

	for(int h = 0;h<NUM_HIDDEN;h++){
		for(int o=0;o<NUM_OUTPUTS;o++)
			HIDDEN_WEIGHTS[h][o] = (((rand()%200) -1.0f) / 100)-1.0f;
	}

     _TRAINER_INIT();

	for (int i = 0;i < NUM_INPUTS ;i++)INPUTS[i].VALUE =  TRAINING_DATA_IN[TRAINING_SET][i];  


return;
}



int _FORWARD_PROPAGATION()
{
	double SUM = 0;
	for (int h = 0;h < NUM_HIDDEN;h++){
		for(int i = 0;i < NUM_INPUTS;i++){
			SUM += (INPUTS[i].VALUE * INPUT_WEIGHTS[i][h]);
		}
		HIDDEN[h].VALUE = Sig(SUM);
	}

	SUM = 0;
	for (int o = 0;o < NUM_OUTPUTS;o++){
		for(int h = 0;h < NUM_HIDDEN;h++){
			SUM += (HIDDEN[h].VALUE * INPUT_WEIGHTS[h][o]);
		}
		OUTPUT[o].VALUE = Sig(SUM);
	}

	return 0;
}


int _BACK_PROPAGATION()
{
	//for (int o = 0;o < NUM_OUTPUTS;o++){
		OUTPUT[0].DELTA = (OUTPUT[0].VALUE * (1.0f - OUTPUT[0].VALUE))  * (TRAINING_DATA_OUT[TRAINING_SET] - OUTPUT[0].VALUE);
	//}
	
	for (int h = 0;h < NUM_HIDDEN;h++){
		HIDDEN[h].DELTA =  (HIDDEN[h].VALUE * (1.0f - HIDDEN[h].VALUE))  * (OUTPUT[0].DELTA* HIDDEN_WEIGHTS[h][0]);
	}
	double ;

	for(int h = 0;h<NUM_HIDDEN;h++){
		for(int o=0;o<NUM_OUTPUTS;o++)
			HIDDEN_WEIGHTS[h][o] += OUTPUT[o].DELTA * L_C;
	}



	for(int i = 0;i<NUM_INPUTS;i++){
		for(int h=0;h<NUM_HIDDEN;h++)
			INPUT_WEIGHTS[i][h] += HIDDEN[h].DELTA  * L_C;
	}



	return 0;
}




double Sig(double x){
return 1.0f / (1.0f + exp(-1.0f * x));
}





void _TRAINER_INIT(){
	        TRAINING_DATA_OUT[0] = 1;//0.0f;


     		TRAINING_DATA_IN[1][1] = 0.0f;
    		TRAINING_DATA_IN[1][2] = 0.0f;
    		TRAINING_DATA_IN[1][3] = 0.0f;TRAINING_DATA_OUT[1] = 0.0f;
    	    
    		TRAINING_DATA_IN[2][1] = 0.0f;
    		TRAINING_DATA_IN[2][2] = 0.0f;
    		TRAINING_DATA_IN[2][3] = 1.0f;TRAINING_DATA_OUT[2] = 1.0f;
 
    		TRAINING_DATA_IN[3][1] = 0.0f;
    		TRAINING_DATA_IN[3][2] = 1.0f;
    		TRAINING_DATA_IN[3][3] = 0.0f;TRAINING_DATA_OUT[3] = 1.0f;
    	
    		TRAINING_DATA_IN[4][1] = 0.0f;
    		TRAINING_DATA_IN[4][2] = 1.0f;
    		TRAINING_DATA_IN[4][3] = 1.0f;TRAINING_DATA_OUT[4] = 0.0f;
    	
    		TRAINING_DATA_IN[5][1] = 1.0f;
    		TRAINING_DATA_IN[5][2] = 0.0f;
    		TRAINING_DATA_IN[5][3] = 0.0f;TRAINING_DATA_OUT[5] = 1.0f;
    	
    		TRAINING_DATA_IN[6][1] = 1.0f;
    		TRAINING_DATA_IN[6][2] = 0.0f;
    		TRAINING_DATA_IN[6][3] = 1.0f;TRAINING_DATA_OUT[6] = 0.0f;
   	
    		TRAINING_DATA_IN[7][1] = 1.0f;
    		TRAINING_DATA_IN[7][2] = 1.0f;
    		TRAINING_DATA_IN[7][3] = 0.0f;TRAINING_DATA_OUT[7] = 0.0f;
    
    		TRAINING_DATA_IN[8][1] = 1.0f;
    		TRAINING_DATA_IN[8][2] = 1.0f;
    		TRAINING_DATA_IN[8][3] = 1.0f;TRAINING_DATA_OUT[8] = 1.0f;

	return;
}






/*

https://www.codeproject.com/Articles/21171/Backpropagation-Artificial-Neural-Network-in-C
void ANNetwork::backprop_run(const float *dsrdvec)
{
    float nrule = m_nrule;  //learning rule
    float alpha = m_alpha;  //momentum
    float delta, dw, oval;

    //get deltas for "output layer"
    for (int n = 0; n < layers[m_layers_number-1]->get_neurons_number(); n++) {
        oval = layers[m_layers_number-1]->neurons[n]->oval;
        layers[m_layers_number-1]->neurons[n]->delta = 
                        oval * (1.0f - oval) * (dsrdvec[n] - oval);
    }

    //get deltas for hidden layers
    for (int l = m_layers_number - 2; l > 0; l--) {
        for (int n = 0; n < layers[l]->get_neurons_number(); n++) {
            delta = 0.0f;

            for (int i = 0; i < layers[l]->neurons[n]->get_output_links_number(); i++)
                delta += layers[l]->neurons[n]->outputs[i]->w * 
                         layers[l]->neurons[n]->outputs[i]->pinput_neuron->delta;

            oval = layers[l]->neurons[n]->oval;
            layers[l]->neurons[n]->delta = oval * (1 - oval) * delta;
        }
    }


    ////////correct weights for every layer///////////////////////////
    for (int l = 1; l < m_layers_number; l++) {
        for (int n = 0; n < layers[l]->get_neurons_number(); n++) {
            for (int i = 0; i < layers[l]->neurons[n]->get_input_links_number(); i++) {
                //dw = rule*Xin*delta + moment*dWprv
                dw = nrule * layers[l]->neurons[n]->inputs[i]->ival * 
                             layers[l]->neurons[n]->delta;       
                dw += alpha * layers[l]->neurons[n]->inputs[i]->dwprv;
                layers[l]->neurons[n]->inputs[i]->dwprv = dw;
                //correct weight
                layers[l]->neurons[n]->inputs[i]->w += dw;  
            }
        }
    }
}*/