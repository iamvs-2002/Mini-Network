#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<string>

using namespace std; 

class Sololearn{     
  unordered_map <string, list<string>> adjList;   
  unordered_map <string, list<string>> users;
  
  public:    
    Sololearn(){     
    }    
    
    void addSkills(string user, list<string> skills = list<string>{}){
      for(string skill : skills)
        users[skill].push_back(user);
    }
    
    void addFriends(string u, list<string> friends){     
      for(string v : friends){
        adjList[u].push_back(v);                
        adjList[v].push_back(u);
      }                
    }                  
    
 void findFriends(string src, list<string> skills = list<string>{}){
      //modified bfs
      //for finding friends of your friends as layer1
      //then their friends as layer2 and so on...
      unordered_map<string, bool> visited; 
      visited[src] = true;
      queue<string> q;
      
      //will help in finding mutual connections
      unordered_map<string, bool> trackNeibr;
      trackNeibr[src]=true;
      
      for(string neighbour : 
      adjList[src]){
        visited[neighbour] = true;
        trackNeibr[neighbour] = true;
      }
      
      unordered_map<string, int> count;
       
      for(string neighbour : adjList[src])
        for(string nextNeibr : adjList[neighbour]){
          if(!visited[nextNeibr])
            q.push(nextNeibr);            
          visited[nextNeibr] = true;
          if(!trackNeibr[nextNeibr])
            count[nextNeibr]++;
        }                      
     
     //looking for mutual connections
      cout<<"Users having mutual connections with you :"<<endl;
      for(auto it : count)
        cout<<it.first<<" ("<<it.second<<" mutual connections)"<<endl;
        
      cout<<endl<<endl;
      
      //users more closed to you will be displayed first
      cout<<"You are a part of this network :"<<endl;                                      
      while(!q.empty()){
        string node = q.front();
        cout<<node<<"\n";
        q.pop();        
        for(string neigbour : adjList[node]){ 
          if(!visited[neigbour]){ 
            q.push(neigbour);                    
            visited[neigbour] = true; 
          }              
        }      
      }
      
      cout<<endl<<endl;            
            
      //looking for language similarity
      for(string skill : skills){
        cout<<"Users knowing "<<skill<<" :"<<endl;
        for(string user : users[skill])
          if(user!=src)
            cout<<user<<endl;
        cout<<endl<<endl;
      }          
    }    
}; 
   

int main(){     
  Sololearn sl;
      
  //Gaurav's network 
  sl.addFriends("Gaurav Agrawal",list<string>{"LukArToDo", "Swapnil Srivastava", "Danijel", "D_Stark", "Dev"});
  //Gaurav's skills
  sl.addSkills("Gaurav Agrawal", list<string>{ "java","kotlin","c","cpp","dsa"});
  
  sl.addFriends("Nilesh", list<string>{"Dev","Ihshu","Aakanksha","Heartless","blackwinter","ChillPill","Rohit Kanojia","Tanay","Prometheus","Namit Jain"});
  sl.addSkills("Nilesh", list<string>{"java","html","css","javascript","php","c#"});
  
  sl.addFriends("Rimjhim", list<string>{"Dev","Tanay","Nilesh"});
  sl.addSkills("Rimjhim", list<string>{"html","css","python"});
 
  sl.addFriends("Namit Jain", list<string>{"Chaithra Gowda","Thayani Gathirvelou","MemeLord Dev"});
  sl.addSkills("Namit Jain", list<string>{"python","javascript","html"});
 
  sl.addFriends("Clueless Coder", list<string>{"Calvin"});
  sl.addSkills("Clueless Coder", list<string>{"python", "javascript"});
 
  sl.addSkills("Chaithra Gowda", list<string>{"c","cpp","java","python"});
 
  sl.addSkills("Daniel", list<string>{"css","html"});
 
  sl.addSkills("Piyush", list<string>{"php","python","html"});  
  
  sl.addSkills("Calvin", list<string>{"html","javascript"});
  
  sl.addSkills("Rajababu Shah",list<string>{"html","python"});
  
  sl.addSkills("Swapnil Srivastava", list<string>{"web","python","swift","cpp"});
  
  sl.addSkills("LukArToDo",list<string>{
  "web","java","kotlin"});
  
  sl.addSkills("Dev", list<string>{"html","c","css","javascript"});
  
  sl.addSkills("Ayan", list<string>{"java","kotlin","android"});  
  

  string name, skillInput, skill="";
  list<string> skills;
  cout<<"Enter your name: ";
  getline(cin, name);
  cout<<"Enter your skills separated by comma: ";
  getline(cin, skillInput);
   
  for(char c : skillInput){
    if(c==','){
      skills.push_back(skill);
      skill.erase();
    }
    else
      skill+=c;
  }
  skills.push_back(skill);
  
  sl.findFriends(name, skills);
   
  return 0;
}







