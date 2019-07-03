#include "BrowserHistory.h"
BrowserHistory::BrowserHistory() {


}

BrowserHistory::~BrowserHistory() {


}

void BrowserHistory::visitSite(Webpage newSite) {
history.push_back(newSite);

navigation.push_back(newSite);
navi = navigation.end();
navi--;

}
string BrowserHistory::getURL() {

return navi->getURL();
}

size_t BrowserHistory::getNavSize() {

return navigation.size();
}

string BrowserHistory::back() {
if(navi != navigation.begin()){
  navi --;
}
return getURL();
}

string BrowserHistory::forward() {
  if(navi != navigation.end()){
    navi ++;
  }
  return getURL();
}

void BrowserHistory::readHistory(string fileName) {
  ifstream myfile(fileName);
   if(myfile.is_open()) {
  cout << "Successfully opened file " << fileName << endl;
    string check;
    string webpageURL;
    time_t timeVisited;
    while(myfile >> check){
      if(check.compare("new")==0)
            {
        myfile >> webpageURL >> timeVisited;
       visitSite(Webpage(webpageURL,timeVisited));
            }
     else if (check.compare("back") == 0){
       back();
          }
     else if (check.compare("forward") == 0){
       forward();
          }
          myfile.close();
     }
   }
}

void BrowserHistory::printBackSites() {
  for(navi = navigation.begin(); navi != navigation.end();navi++){
    cout << navi -> getURL() << endl;
    }

}

void BrowserHistory::printForwardSites() {
  for(navi = navigation.begin(); navi != navigation.end();navi++){
    cout << navi -> getURL() << endl;
    }
}
void BrowserHistory::printFullHistory() {
  for(navi = history.begin(); navi != history.end();navi++){
    cout << navi -> getURL() << endl;
    }
}
