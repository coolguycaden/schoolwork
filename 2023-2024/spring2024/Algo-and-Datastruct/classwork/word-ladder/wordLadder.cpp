#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> V; //words from wordlist05.txt

//Words from wordlist05.txt put into a wordmap
//used to check if a 5-letter word exists
unordered_map<string, string> wordMap;	

//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type
//Taken from Lab 10
unordered_map<string, bool> visited;         // have we queued up this state for visitation?
unordered_map<string, string> pred;           // predecessor state we came from
unordered_map<string, int> dist;             // distance (# of hops) from source node
unordered_map<string, vector<string>> nbrs;   // vector of neighboring words


//Modified BFS from Lab 10
vector<string> search(string startWord, string targetWord, int &steps){
	
	//Nodes that have not been visited yet
	queue<string> toVisit;

	//Mark starting word for visitation, and as visited
	toVisit.push(startWord);
	visited[startWord] = true;
	dist[startWord] = 0;

	//This while hold the path taken to get from
	//startWord to targetWord
	vector<string> finalPath;

	while(!toVisit.empty()){ //&& loop < 80){
		string currentNode = toVisit.front();
		toVisit.pop();
		
		for(string n : nbrs[currentNode]){
			
			if(!visited[n]){
				pred[n] = currentNode;
				visited[n] = true;
				dist[n] = 1 + dist[currentNode]; 
				toVisit.push(n);
			}
			
			if(n == targetWord){
				steps = dist[n];
				finalPath.resize(steps);
				string temp = n;
				
				//Works backwards from the found word, creating a path that
				//is possible to from the startWord to targetWord
				for(int x = finalPath.size() - 1; x >= 0; x--){
					finalPath[x] = temp;
					temp = pred[temp]; 

				}
				
				return finalPath;
			}
		}
	}
	
	return finalPath;
}
//Reads in words from wordlist and hashes them in a hash map
//then returns that map
void createStringMap(string fileName){
	fstream file(fileName); 
	string word;
	
	while(getline(file, word)){
		wordMap.insert({word, word});
		V.push_back(word);
	}
}

//Checks if a exists by checking the provided hash map if the word
//is in the map, this assumes the map sent-in is the list of all 5-letter words
bool isRealWord(string * word){

	unordered_map<string, string>::iterator find = wordMap.find(*word);

	if(find == wordMap.end()){
		return false;
	} else {
		return true;
	}

	return false;
}

//unordered_map<string, vector<string>> nbrs;   // vector of neighboring states

//Creates a graph where each word leads to nodes that are one letter in difference
//from preceding node
void createGraph(){
	for(int x = 0; x < V.size(); x++){

		vector<string> possibleWords;
		
		//ascii values for lowercase letters
		//a-z ( a is 95, z is 122)
		//this will enumerate through the chars and
		//find if a word exists with a letter in that spot
		for(int y = 0; y < V[x].size(); y++){
			string temp = V[x];
			for(char z = 97; z <= 122; z++){
				temp[y] = z;
				if(temp != V[x] && isRealWord(&temp)){
					possibleWords.push_back(temp);
					string label = V[x] + " -> " + temp;
			
				}
			}
		}

		nbrs.insert(pair<string, vector<string>>(V[x], possibleWords));
	}
}	


void wordLadder(string s, string t, int &steps, vector<string> &p)
{
	
	createStringMap("wordlist05.txt");
	
	createGraph();

	if(isRealWord(&t)){
		p = search(s, t, steps);	
	}
	
}

/*
int main(void)
{
	int steps = 0;
	string s, t;
	vector<string> path;

	cout << "Source: ";
	cin >> s;

	cout << "Target: ";
	cin >> t;

	wordLadder(s, t, steps, path);

	if (steps == 0)
	{
		cout << "No path!\n";
	}
	else
	{
		cout << "Steps: " << steps << "\n\n";
		for (int i=0; i<path.size(); i++)
		{
			cout << path[i] << endl;
		}
	}
	return 0;
}*/
