#include"list.h"

list lrandom(int size){

  list new_list;

  new_list.size = size;
  new_list.array_ptr = (int*) malloc(sizeof(int)*size);


  for(int i =0 ; i<size;i++){
    
    new_list.array_ptr[i] = rand();
    
  }

  return new_list;
}

list lcopy(list l){

  list new_list;

  new_list.size = l.size;
  new_list.array_ptr = (int*) malloc(sizeof(int)*l.size);

  for(int i =0;i<new_list.size;i++){

    new_list.array_ptr[i] = l.array_ptr[i];
  }

  return new_list;
}

int amount_of_chars(int n){

  if(n==0){
    return 1;
  }
  
  int amount = n < 0 ? 1 : 0;

  while(n!=0){

    amount++;
    n/=10;
    
  }
  
  
  return amount;
  
}

int compute_number_chars(list l){


  int size = l.size;
  int total_size = 0;
  
  for(int i=0;i<size;i++){

    int n = l.array_ptr[i];
   
    total_size += amount_of_chars(n);
    
  }

  return total_size;

  
}


char* to_string(list l){


  int spec_caracter_size = 2 + l.size;

  int numbers_size = compute_number_chars(l);

  int total_size = spec_caracter_size + numbers_size;
  
  char* representation_ptr = (char*) malloc(sizeof(char)*total_size);

  char* current_ptr = representation_ptr+1;

  representation_ptr[0] = '[';
  
  int is_separator = 0;
  
  for(int i=0;i<l.size;i++){
    
    int n = l.array_ptr[i];

    if(!is_separator){

      sprintf(current_ptr,"%d",n);
      is_separator =1;
	}else {

      sprintf(current_ptr,",%d",n);
      current_ptr +=1;
     
    }

    current_ptr += amount_of_chars(n);
    
    
  }

  current_ptr[0] = ']';
  current_ptr[1] = '\0';

  return representation_ptr;
}


list append(list l, list m){

  int size = l.size + m.size;
  list new_list;

  new_list.size = size;
  

  int* array_ptr = (int*) malloc(sizeof(int)*size);


  for(int i =0;i<l.size;i++){

    array_ptr[i] = l.array_ptr[i];
    
  }

  for(int i=0;i<m.size;i++){

    array_ptr[i+l.size] = m.array_ptr[i];

    
  }

  new_list.array_ptr = array_ptr;
				 
  return new_list;
}
