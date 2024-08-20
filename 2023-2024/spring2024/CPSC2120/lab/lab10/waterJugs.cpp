/*
 * Name: Caden Allen
 * Date Submitted: 4/22/2024
 * Lab Section: 001
 * Assignment Name: Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
	"Fill B",
	"Empty A",
	"Empty B",
	"Pour A->B",
	"Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
	queue<state> to_visit;
	to_visit.push(source_node);
	visited[source_node] = true;
	dist[source_node] = 0;

	while (!to_visit.empty()) {
		state curnode = to_visit.front();
		to_visit.pop();
		for (state n : nbrs[curnode])
			if (!visited[n]) {
				pred[n] = curnode;
				dist[n] = 1 + dist[curnode];
				visited[n] = true;
				to_visit.push(n);
			}
	}
}

// GENERIC
void print_path(state s, state t)
{
	if (s != t) {
		print_path(s, pred[t]);
		cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
	} else {
		cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
	}
}

//typedef pair<int,int> state;



//Does an action from const actions[5]
//Each case number is the index of the action done
//For example, case 0 would be "Fill A"
//case 1, "Fill B", so on so forth
state doAction(int action, int a, int b){
	
	switch(action){
		
		//Fill A
		case 0:
			return state(3, b);
		
		//Fill B
		case 1:
			return state(a, 4);
		
		//Empty A
		case 2:
			return state(0, b);

		//Empty B
		case 3:
			return state(a, 0);
		
		//Pour A into B
		case 4:
			while(a > 0 && b < 4){
				a -= 1;
				b += 1;
			}

			return state(a, b);
		
		//Pour B into A
		case 5:
			while(a < 3 && b > 0){
				b -= 1;
				a += 1;
			}

			return state(a, b);
	};

	//default return
	return state(0, 0); 
}

//Exact same as doAction, but checks if an action is possible
//For example, if jug A (action of 0) is full, you cannot fill it
bool isActionPossible(int action, int a, int b){
	switch(action){
		case 0:
			return (a < 3);

		case 1:
			return (b < 4);

		case 2: case 4:
			return (a > 0);

		case 3: case 5:
			return (b > 0);
		
	};

	return false;
}

void build_graph(void)
{
	for(int x = 0; x <= 3; x++){
		for(int y = 0; y <= 4; y++){
			state currentState(x, y);
			vector<state> possibleActions;
			
			for(int z = 0; z <= 5; z++){
				int a = get<0>(currentState);
				int b = get<1>(currentState);
				
				//Checks is an action is possible, if so, then it is
				//a possible action
				if(isActionPossible(z, a, b)){
					state result = doAction(z, a, b);

					possibleActions.push_back(result);
					edge_label.insert(pair< pair< state, state>, string>
							(pair<state, state>(currentState, result), actions[z])); 
				}
			}
			nbrs.insert(pair<state, vector<state>>(currentState, possibleActions));
		}
	}
	

}

