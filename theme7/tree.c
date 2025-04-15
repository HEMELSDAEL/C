#include <stdlib.h>
#include <stdio.h>

typedef struct node{
  int value;
  struct node *left;
  struct node *right;
} tree_t;

tree_t *construct(tree_t *left, tree_t *right){
  tree_t *new_node = (tree_t *)malloc(sizeof(tree_t));
  if(new_node == NULL){
    return NULL;
  }
  new_node->value = 0;
  new_node->left = left;
  new_node->right = right;
  return new_node;
}

void display(tree_t *root){
  if(root!=NULL){
    printf("%d", root->value);
    display(root->left);
    display(root->right);
  }
}

void destroy(tree_t **root_ptr){
  if(*root_ptr != NULL){
    destroy(&((*root_ptr)->left));
    destroy(&((*root_ptr)->right));
    free(*root_ptr);
    *root_ptr = NULL;
  }
}

int verify(tree_t *root){
  if(root == NULL){
    return 1;
  }

  if(root->left != NULL && root->left->value >= root->value){
    return 0;
  }

  if(root->right != NULL && root->right->value <= root->value){
    return 0;
  }

  if(!verify(root->left) || !verify(root->right)){
    return 0;
  }

  return 1;
}

tree_t *search(tree_t *root){
  int target;
  printf("Entrez le numéro du noeud à rechercher :");
  scanf("%d", &target);
  while (root != NULL){
    if(root->value == target){
      return root;
    }else if(target < root->value){
      root = root->left;
    }else{
      root = root->right;
    }
  }
  return NULL;
}

tree_t *insert(tree_t *root, int val){
  if(root == NULL){
    tree_t *new_node = (tree_t *)malloc(sizeof(tree_t));
    if(new_node == NULL){
      return NULL;
    }
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
  if(val < root->value){
    root->left = insert(root->left, val);
  }
  else if(val> root->value){
    root->right = insert(root->right, val);
  }
  return root;
}
     
int main(){
  tree_t *root = NULL;
  int choix;
  int valeur;
  do{
    printf("\nMenu:\n");
    printf("1 -  Insérer un noeud\n");
    printf("2 - Rechercher un noeud\n");
    printf("0 - Quitter\n");
    printf("Choix ?");
    scanf("%d", &choix);

    switch(choix){
    case 1:
      printf("Entrez la valeur du noeud à insérer : ");
      scanf("%d", &valeur);
      root = insert(root, valeur);
      break;
    case 2:
      printf("Entrez la valeur du noeud à rechercher : ");
      scanf("%d", &valeur);
      if(search(root) != NULL){
	printf("Le noeud avec la valeur %d a été trouvé dans l'arbre\n", valeur);
      }else{
	printf("Le noeud avec la valeur %d n'a pas été trouvé dans l'arbre\n", valeur);
      }
      break;
    case 0:
      printf("Au revoir!\n");
      break;
    default:
      printf("Choix invalide. Veuillez recommencer\n");
      break;
    }
  }
  while(choix!=0);
  destroy(&root);
  return 0;
}
  
