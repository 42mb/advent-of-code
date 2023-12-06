#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct sym {
    std::pair<int, int> coordinate{};
    char digit{};
    std::vector<int>numbers{};
};

struct nmb{
    std::pair<int, int> coordinate{};
    int len{};
    int nmb;
    std::vector<std::pair<int, int>> coordinatesAround;
};

int main() {
    std::ifstream myfile ("/home/archi/Projects/adventofcode/2023/day03CPP/day3.prod");
    std:: string line {};
    std::vector<sym> symbolList{};
    std::vector<nmb> numberList{};
    int x{}, y{};
    if(!myfile.is_open()) {
        std::cout << "file not found";
    } else {
        while ( std::getline (myfile, line)) {
            x=0;
        for(int xx =0; xx<line.length(); ++xx) {
                if(isdigit(line[xx]) == false && line[xx]!='.') {
                    symbolList.push_back(sym({xx,y}, line[xx]));
                }
                if(isdigit(line[xx])) {
                    int len{};
                    std::string nmb;
                    int coordinateX = xx;
                    int coordinateY = y;
                    while(isdigit(line[xx])){
                        len++;
                        nmb+=line[xx];
                        xx++;
                    }
                    xx-=1;
                    std::vector<std::pair<int, int>> coordAround{};
                    coordAround.emplace_back(coordinateX-1, coordinateY);
                    coordAround.emplace_back(coordinateX+len, coordinateY); //??
                    for( int t = -1; t<len+1; ++t) {
                        coordAround.emplace_back(coordinateX+t, coordinateY-1);
                        coordAround.emplace_back(coordinateX+t, coordinateY+1);
                        ///////////////////////
                        //####
                        //#23#      coorAround should be the #
                        //####
                        ////////////////
                    }
                    struct nmb N({coordinateX, coordinateY}, len, std::stoi(nmb), coordAround);
                    numberList.push_back(N);
                }
            }
            y++;
        }
        myfile.close();
    }

    int sum{};
    for(auto &nmb:numberList) {
        for(auto & around: nmb.coordinatesAround) {
            bool isAround{false};
            for(auto &sym: symbolList) {
               if(sym.coordinate.first == around.first && sym.coordinate.second == around.second) {
                   if(sym.digit == '*') {
                       sym.numbers.emplace_back(nmb.nmb);
                   }
                  isAround = true;
               }
            }
            if(isAround) {
                sum+=nmb.nmb;
            }
        }
    }
    std::cout<<"Part1:   "<<  sum  <<"\n";

    int gearRatioSum{};
    for(auto &gears:symbolList) {
        if(gears.numbers.size() == 2) {
            gearRatioSum+= gears.numbers[0] * gears.numbers[1];
        }
    }
    std::cout << "Part2: " << gearRatioSum;

    return 0; //result p1: 507214  p2: 72553319
}
