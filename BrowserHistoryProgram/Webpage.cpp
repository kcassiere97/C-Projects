#include "Webpage.h"

Webpage::Webpage() {
  url = "  ";
  time = 0.00;
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
   url = webpageURL;
   time = timeVisited;
}

string Webpage::getURL() {

    return url;
}

time_t Webpage::getTime() {

    return time;
}
