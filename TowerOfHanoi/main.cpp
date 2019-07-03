//
//  main.cpp
//  towerOfHanoi
//
//  Created by Kizar Cassiere on 4/17/18.
//  Copyright © 2018 Kizar Cassiere. All rights reserved.
//

#include <iostream>
#include <vector>


//void tower(int, char, char, char);

//insert main

//void tower(int i, char start, char end, char temp){
//
//    if(i == 0){std::cout <<"Must Have Rings!" << std::endl; return;}
//
//    else if(i == 1){
//
//      printf("\n Move Ring from START %c --> END %c", start, end);
//        printf("\n ");
//        return;
//    }
//    else{
//        tower(i-1, start, temp, end);
//        printf("\n Move Ring '%d' from START %c --> END %c",  i, start, end);
//        tower(i-1, temp, end, start);
//        printf("\n ");
//        return;
//    }
//
//}

std:: vector<size_t> src {6,5,4,3,2,1}, other,dest;

void printpeg(const std:: string& label, const std::vector<size_t>&peg){
    
    std::cout << label;
    for(auto ring : peg){
        
        std::cout << ring << " ";}
        std::cout << "\n";
}

void printpage(){
    
     printpeg("SRC:   ", src);
     printpeg("OTHER:   ", other);
     printpeg("DEST:   ", dest);
     std::cout <<"\n";
}

void  moveone(std::vector<size_t>&src, std::vector<size_t>&dest){
    
    printpage(); //might be pringpeg();
    size_t ring = src.back();
    src.pop_back();
    dest.push_back(ring);
}

void move(std::vector<size_t>& src, std::vector<size_t>& dest,std::vector<size_t>& other,size_t rings){
    
    if(rings == 1){
        
        move(src,other,dest,rings - 1);
        moveone(src,dest);
        move(other,dest,src,rings - 1);
    }
}

int main(int argc, const char * argv[]) {
    
    size_t rings;
    
    //    std::cout<< "Enter number of rings: " << std::endl;
    
    //    std::cin >>input;
    //
    //    tower(input, 'A', 'B', 'C');
    //    std::cout << " 0==[*]::::::::::::::::>  DONE! ☺ " << std::endl;
    //
    //    printf("\n ");
    return 0;
}


