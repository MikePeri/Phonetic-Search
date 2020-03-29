//Authors names:Ilana shuchman and Michael Perry
#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>
using namespace phonetic;
using namespace std;
/*
Real sentence checking by online sentence generator:
https://sentence.wordhippo.com/
online generator of words by letters:
https://wordfinder.yourdictionary.com/
1.Checking long text
2.Checking special cases
3.Checking of placing the word in different places
4.Checking Lower-Higher Case
5.Checking the word with sign in the end
6.Checking swapping the words by blocks
*/

TEST_CASE("Long Text") {

string text = "Pedti fudder buOjhd a Pyt of botder fut zhe sayt dhys fotterz bytter Ip Y fod id yn mi batter Yt VyLL mace mI PaDter fidder Put a byt u pedder fODter Will maqe mi fadder pedter Dhen she poojht a byt u botder Petder dhan the fytter pudder Mate her bydder paDDer fedter zo dvaz pedder Betti Putter fuughd a fid o better pudter";

/* The original:
Betty Botter bought a bit of butter 
But she said this butters bitter
If I put it in my batter
It will make my batter bitter
But a bit o better butter
Will make my batter better
Then she bought a bit o butter
Better than the bitter butter
Made her bitter batter better
So twas better Betty Botter
Bought a bit o better butter*/

    CHECK(find(text, "Betty") == string("Pedti"));
    CHECK(find(text, "botter") == string("fudder"));
    CHECK(find(text, "bought") == string("buOjhd"));
    CHECK(find(text, "bit") == string("Pyt"));

    CHECK(find(text, "butter") == string("fudder"));
    CHECK(find(text, "put") == string("fut"));
    CHECK(find(text, "she") == string("zhe"));


    CHECK(find(text, "said") == string("sayt"));
    CHECK(find(text, "this") == string("dhys"));
    CHECK(find(text, "butters") == string("fotterz"));
    CHECK(find(text, "bitter") == string("bytter"));

    CHECK(find(text, "if") == string("Ip"));
    CHECK(find(text, "I") == string("Y"));
    CHECK(find(text, "it") == string("id"));
    CHECK(find(text, "in") == string("yn"));

    CHECK(find(text, "my") == string("mi"));
    CHECK(find(text, "will") == string("VyLL"));
    CHECK(find(text, "make") == string("mace"));
    CHECK(find(text, "but") == string("fut"));

    CHECK(find(text, "o") == string("u"));
    CHECK(find(text, "then") == string("Dhen"));
    CHECK(find(text, "than") == string("dhan"));
    CHECK(find(text, "the") == string("the"));

    CHECK(find(text, "made") == string("Mate"));
    CHECK(find(text, "so") == string("zo"));
    CHECK(find(text, "twas") == string("dvaz"));
}

TEST_CASE("Test special cases") {

  CHECK_THROWS(find("", "c"));
  CHECK_THROWS(find("Hello", ""));
  CHECK_THROWS(find("Hello", "c"));
  CHECK_THROWS(find("Hello", "Hell"));

  CHECK(find("Hello         ", "Hello") == string("Hello"));
  CHECK(find("        Hello", "Hello") == string("Hello"));



}

TEST_CASE("Test placing the specific word") {
    string text = " happy xxx yyy ";
    CHECK(find(text, "happy") == string("happy"));
    text = " xxx happy yyy ";
    CHECK(find(text, "happy") == string("happy"));
    text = " xxx yyy happy ";
    CHECK(find(text, "happy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Not exactly known as slouches in the recording studio this is still not the kind of behaviour we expect from recording artists these days";
    CHECK(find(text, "NOT") == string("Not"));
    CHECK(find(text, "NOt") == string("Not"));
    CHECK(find(text, "Not") == string("Not"));
    CHECK(find(text, "nOT") == string("Not"));
    CHECK(find(text, "noT") == string("Not"));
    CHECK(find(text, "not") == string("Not"));
}

//Checking The Block of b,f,p:
//Starting with p letter
TEST_CASE("Test replacement of p to (b or f)") {
    string text = "She would have wanted us all to be happy and to have fun so that is what we will do";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));

    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
}
//Starting with b letter
TEST_CASE("Test replacement of b to (p or f)") {
    string text = "His knowledge is mostly self taught and is the result of his passion for wine as a hobby";
    CHECK(find(text, "hobby") == string("hobby"));
    CHECK(find(text, "hopby") == string("hobby"));
    CHECK(find(text, "hobpy") == string("hobby"));
    CHECK(find(text, "hoppy") == string("hobby")); 

    CHECK(find(text, "hofby") == string("hobby"));
    CHECK(find(text, "hobfy") == string("hobby"));
    CHECK(find(text, "hoffy") == string("hobby"));     
}
//Starting with f letter
TEST_CASE("Test replacement of f to (b or p)") {
    string text = "Blind Lemon recently released their debut self-titled album which showcases the bands range of sounds from swing and shuffle to slow blues";
    CHECK(find(text, "shuffle") == string("shuffle"));
    CHECK(find(text, "shubble") == string("shuffle"));
    CHECK(find(text, "shubfle") == string("shuffle"));
    CHECK(find(text, "shufble") == string("shuffle"));

    CHECK(find(text, "shupple") == string("shuffle"));
    CHECK(find(text, "shupfle") == string("shuffle"));
    CHECK(find(text, "shufple") == string("shuffle"));
}
//Checking The Block of v,w:
//Starting with v letter
TEST_CASE("Test replacement of v to w") {
    string text = "He did not recommend driving westwardly as it was feared a large volume of water would be tapped";
    CHECK(find(text, "volume") == string("volume"));
    CHECK(find(text, "wolume") == string("volume"));
}

//Starting with w letter
TEST_CASE("Test replacement of w to v") {
    string text = "But it was the pumpkin ravioli with crisp sage leaves which won hands down for wow flavour";
    CHECK(find(text, "wow") == string("wow"));
    CHECK(find(text, "vov") == string("wow"));
    CHECK(find(text, "wov") == string("wow"));
    CHECK(find(text, "vow") == string("wow"));
}
//Combining v+w
TEST_CASE("Test the combining:v,w together") {
    string text = "Critics view the decision as an example of moral bankruptcy on the part of the administration";
    CHECK(find(text, "view") == string("view"));
    CHECK(find(text, "viev") == string("view"));
    CHECK(find(text, "wiew") == string("view"));
    CHECK(find(text, "wiev") == string("view"));
}
//Checking The Block of g,j:
//Starting with g letter
TEST_CASE("Test replacement of g to j") {
    string text = "It creates a nexus of links that increase the chance that the calumny will come to the top of a google search";
    CHECK(find(text, "google") == string("google"));
    CHECK(find(text, "joojle") == string("google"));
    CHECK(find(text, "joogle") == string("google"));
    CHECK(find(text, "goojle") == string("google"));
}

//Starting with j letter
TEST_CASE("Test replacement of j to g") {
    string text = "Theres been a quantum jump in threats";
    CHECK(find(text, "jump") == string("jump"));
    CHECK(find(text, "gump") == string("jump"));
    
}
//Combining g+j
TEST_CASE("Test the combining:g,j together") {
    string text = "Two brown finish thimbles under the barrel secure the wooden ramrod with its brass tip threaded for jag worm screw or other implement";
    CHECK(find(text, "jag") == string("jag"));
    CHECK(find(text, "jaj") == string("jag"));
    CHECK(find(text, "gag") == string("jag"));
    CHECK(find(text, "gaj") == string("jag"));
}
//Checking The Block of c, k, q:
//Starting with c letter
TEST_CASE("Test replacement of c to (k or q)") {
    string text = "To rethink the concept of popular sovereignty beyond the nation-state appears to entail a contradiction in terms";
    CHECK(find(text, "concept") == string("concept"));
    CHECK(find(text, "konkept") == string("concept"));
    CHECK(find(text, "koncept") == string("concept"));
    CHECK(find(text, "conkept") == string("concept"));

    CHECK(find(text, "qonqept") == string("concept"));
    CHECK(find(text, "qoncept") == string("concept"));
    CHECK(find(text, "conqept") == string("concept"));
}

//Starting with k letter
TEST_CASE("Test replacement of k to (c or q)") {
    string text = "It prevents a hacker from deleting any files but restricts a user from suing the hacker should anything be accidentally erased";
    CHECK(find(text, "hacker") == string("hacker"));
    CHECK(find(text, "haccer") == string("hacker"));
    CHECK(find(text, "hacqer") == string("hacker"));
}

//Starting with q letter
TEST_CASE("Test replacement of q to (k or c)") {
    string text = "Born in 1542 she married the French Dauphin in 1558 and became the queen consort a year later";
    CHECK(find(text, "queen") == string("queen"));
    CHECK(find(text, "kueen") == string("queen"));
    CHECK(find(text, "cueen") == string("queen"));
}
//Combining c, k, q
TEST_CASE("Test the combining:c, k, q together") {
    string text = "The popularity of diet fads is a testimony to the fact that people want a quick fix for their health and weight problems";
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "cuicc") == string("quick"));
    CHECK(find(text, "quiqq") == string("quick"));
    CHECK(find(text, "kuikk") == string("quick"));
    CHECK(find(text, "quiqk") == string("quick"));
    CHECK(find(text, "quicq") == string("quick"));
    CHECK(find(text, "quikk") == string("quick"));
    CHECK(find(text, "kuick") == string("quick"));
    CHECK(find(text, "quicc") == string("quick"));
    CHECK(find(text, "cuick") == string("quick"));
}
//Checking The Block of s,z:
//Starting with s letter
TEST_CASE("Test replacement of s to z") {
    string text = "The network is disappointed with the decision to suspend accreditation to our journalists";
    CHECK(find(text, "suspend") == string("suspend"));
    CHECK(find(text, "zuzpend") == string("suspend"));
    CHECK(find(text, "zuspend") == string("suspend"));
    CHECK(find(text, "suzpend") == string("suspend"));
}
//Starting with z letter
TEST_CASE("Test replacement of z to s") {
    string text = "My experiences with Mazda rotaries has left me an ardent enthusiast of the engine for life";
    CHECK(find(text, "Mazda") == string("Mazda"));
    CHECK(find(text, "Masda") == string("Mazda"));
}
//Combining s+z
TEST_CASE("Test the combining:s,z together") {
    string text = "The size of his offer indicates that he is eager to buy the house";
    CHECK(find(text, "size") == string("size"));
    CHECK(find(text, "zise") == string("size"));
    CHECK(find(text, "sise") == string("size"));
    CHECK(find(text, "zize") == string("size"));
}
//Checking The Block of d,t:
//Starting with d letter
TEST_CASE("Test replacement of d to t") {
    string text = "My daddy is a bit of a tennis nut himself so I'm following in his footsteps";
    CHECK(find(text, "daddy") == string("daddy"));
    CHECK(find(text, "tatty") == string("daddy"));
    CHECK(find(text, "taddy") == string("daddy"));
    CHECK(find(text, "tatdy") == string("daddy"));
    CHECK(find(text, "dadty") == string("daddy"));
    CHECK(find(text, "datty") == string("daddy"));
}
//Starting with t letter
TEST_CASE("Test replacement of t to d") {
    string text = "The nutritive value of timothy however was superior to other forages at the more mature stage";
    CHECK(find(text, "timothy") == string("timothy"));
    CHECK(find(text, "dimodhy") == string("timothy"));
    CHECK(find(text, "dimothy") == string("timothy"));
    CHECK(find(text, "timodhy") == string("timothy"));
}
//Combining t+d
TEST_CASE("Test the combining:t,d together") {
    string text = "If the patient does not know of any tender area make a very light survey of the four quadrants with your examining hand";
    CHECK(find(text, "tender") == string("tender"));
    CHECK(find(text, "denter") == string("tender"));
    CHECK(find(text, "tenter") == string("tender"));
    CHECK(find(text, "dender") == string("tender"));
}
//Checking The Block of o,u:
//Starting with o letter
TEST_CASE("Test replacement of o to u") {
    string text = "Alas the upshot is that I've missed nine years pensions contributions oops";
    CHECK(find(text, "oops") == string("oops"));
    CHECK(find(text, "uups") == string("oops"));
    CHECK(find(text, "oups") == string("oops"));
    CHECK(find(text, "uops") == string("oops"));
}
//Starting with u letter
TEST_CASE("Test replacement of u to o") {
    string text = "Then theres her infamous  wardrobe malfunction  at the Super Bowl half time ceremony.";
    CHECK(find(text, "Super") == string("Super"));
    CHECK(find(text, "Soper") == string("Super"));
}
//Combining u+o
TEST_CASE("Test the combining:u,o together") {
    string text = "He sounded matter of fact when he told us good news and somehow sounded very convincing when he came out with the not so good news as well";
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "uut") == string("out"));
    CHECK(find(text, "oot") == string("out"));
    CHECK(find(text, "uot") == string("out"));
}
//Checking The Block of i,y:
//Starting with i letter
TEST_CASE("Test replacement of i to y") {
    string text = "At the rate he is going it looks like his strategy could backfire and he could soon be out on his ear";
    CHECK(find(text, "like") == string("like"));
    CHECK(find(text, "lyke") == string("like"));
}
//Starting with y letter
TEST_CASE("Test replacement of y to i") {
    string text = "Seasonal Affective Disorder patients tend to exhibit hyperphagia and carbohydrate cravings symptoms typical of inadequate brain serotonin";
    CHECK(find(text, "carbohydrate") == string("carbohydrate"));
    CHECK(find(text, "carbohidrate") == string("carbohydrate"));
}
//Combining i+y
TEST_CASE("Test the combining: i,y together") {
    string text = "He has also been silly enough to make Kumble sit on the bench in many matches";
    CHECK(find(text, "silly") == string("silly"));
    CHECK_THROWS(find(text, "sliiy"));
    CHECK_THROWS(find(text, "slily"));
    CHECK_THROWS(find(text, "siily"));
    CHECK_THROWS(find(text, "siiiy"));
    CHECK_THROWS(find(text, "sllly"));
}
