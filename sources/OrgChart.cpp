#include "OrgChart.hpp"
using namespace std;
#include <queue>
#include <bits/stdc++.h>
namespace ariel
{

    //constructor
    OrgChart:: OrgChart(){
        head.name  = "";
        head.visited = false;
    }
    //add root
    OrgChart &OrgChart::add_root(string  const &name)
    { 
       
       head.name = name;
       head.visited = false;
       head.level = t;
       
       if(children.empty()){
       children.push_back(head);
       }
       else{
        children[0].name = name;
       }
        children[0].level = t;

        return *this;
    }

    //add sub
    OrgChart &OrgChart::add_sub(string const &father, string child){
        
         Node child1;
        child1.name=move(child);
        child1.visited = false;
        bool flag = false;
        for(unsigned int i = 0;i<children.size();i++){
            if(children[i].name==father){
            flag = true;
            child1.level = children[i].level+1;
            children.push_back(child1);
            children[i].fam.push_back(child1);
            children[i].fam.back().level =children[i].level+1;
            if(maxlevel<children[i].level+1){
                maxlevel = children[i].level+1;
            }
            break;
            } 
        }
        if(!flag){
            throw invalid_argument( "no such father" );

        }
       
      
    return *this;
    }
    //begin level order
     string *OrgChart::begin_level_order(){
        if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
        b_l_o.clear();
        temp2.clear();
        init(children[0]);
         b_l_o.push_back(children[0].name);
        temp2.push_back(children[0]);

      for(unsigned i =0;i<children.size();i++){
       begin_level_order1(children[i]);
      }
       for(unsigned int i = 0;i<children.size();i++){
           children[i].visited = false;
       }
        init(children[0]);

       return &b_l_o[0];
     }
    bool OrgChart::begin_level_order1(Node &n){
        for(unsigned i =0;i<n.fam.size();i++){
            for(unsigned j =0;j<children.size();j++){
                if(children[j].name==n.fam[i].name && !children[j].visited){
                 b_l_o.push_back(children[j].name);
                 temp2.push_back(children[j]);
                 children[j].visited = true;
                }
            }
        }
      
             return true;

    }
    //end level order
    string *OrgChart::end_level_order(){
        if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
     return &b_l_o[b_l_o.size()];
    }

   //begin reverse order
   string *OrgChart::begin_reverse_order(){
       if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
    init(children[0]);

     b_r_o.clear();
     temp.clear();
     b_r_o.push_back(children[0].name);
       int curr=0;
       for(unsigned i =0;i<children.size();i++){
           if(curr<children[i].level){
               curr = children[i].level;
               reverse(temp.begin(),temp.end());
               for(unsigned j =0;j<temp.size();j++){
                   b_r_o.push_back(temp[j].name);
               }
               temp.clear();
           }
       end_level_order1(children[i]);
       }
   reverse(b_r_o.begin(),b_r_o.end());
   for(unsigned int i = 0;i<children.size();i++){
           children[i].visited = false;
       }
               init(children[0]);

       return &b_r_o[0];
   }

    bool OrgChart::end_level_order1(Node &n){
          for(unsigned i =0;i<n.fam.size();i++){
            for(unsigned j =0;j<children.size();j++){
                if(children[j].name==n.fam[i].name && !children[j].visited){
                 temp.push_back(children[j]);
                 children[j].visited = true;
                }
            }
        }
             return true;
    }
    
    //end reverse order
    string *OrgChart::reverse_order(){
        if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
         return &b_r_o[b_r_o.size()];

    }
   
    //begin preorder
    string *OrgChart::begin_preorder(){
        for(unsigned int i = 0;i<children.size();i++){
           children[i].visited = false;
       }
        if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
                init(children[0]);

        b_p.clear();
         begin_preorder1(children[0]);
         for(unsigned int i = 0;i<children.size();i++){
           children[i].visited = false;
       }
               init(children[0]);

       return &b_p[0];

    }
     bool OrgChart::begin_preorder1(Node &n){
      
        b_p.push_back(n.name);         
         for(unsigned i =0;i<n.fam.size();i++){
             for(unsigned j = 0;j<children.size();j++){
                 if(children[j].name==n.fam[i].name  && !children[j].visited){
                       children[j].visited=true;
                n.fam[i].visited=true;
              if(begin_preorder1(children[j]) ){
               return true;
           } 
          }
         }
        }
        return false;
    }

    //end preorder
    string *OrgChart::end_preorder(){
        if(children.empty()){
        throw invalid_argument( "empty tree" );
        }
        begin_preorder();
       return &b_p[b_p.size()];

    }

    bool OrgChart::init(Node &n){
         for(unsigned i =0;i<n.fam.size();i++){
             for(unsigned j = 0;j<children.size();j++){
                 if(children[j].name==n.fam[i].name  && children[j].visited){
                       children[j].visited=false;
                       n.fam[i].visited=false;
              if(begin_preorder1(children[j]) ){
               return true;
           } 
          }
         }
        }
        return false;


    }
    string *OrgChart::begin(){
    return begin_level_order();

    }

    string *OrgChart::end(){
        return end_level_order();
    }
    
   //output
    ostream &operator<<(ostream &os, OrgChart &org){     
        for(unsigned i =0;i<org.children.size();i++){
         os << "father:" + org.children[i].name+ "|";
         os << "children:";
         if(!org.children[i].fam.empty()){
          for(unsigned j =0;j<org.children[i].fam.size();j++){
         os << "," + org.children[i].fam[j].name;
          
         }
         }
         else{
         os << "no children";    
         }
         os << "|" << endl;
      }
        
    os<< "";
  
  return os;
        
    }
}