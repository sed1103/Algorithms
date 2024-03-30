#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct adjlistnode
{
   int vertex;
   int weight;
   struct adjlistnode *next;
}adjlistnode;

adjlistnode *newadjlistnode(int , int );

typedef struct heapnode
{
   int vertex;
   int cost;
}heapnode;
heapnode *newheapnode(int , int);

typedef struct heap
{
    int currentsize;
    int maxsize;
    int *pos;
    struct heapnode **array;
}heap;

adjlistnode *head[200];

int V;
int E;
int start = 0;
int cost[200];
int parent[200];
int minCostVertex;
int minCost;



void readfile();
void insertadjver(int ,int , int );
heap *Buildheap(int );
void prins(int);
void decreaseKey(heap* , int , int);
void swap(heapnode **, heapnode **);
heapnode *extractMin(heap *);
void minHeapify(heap *, int );




int main()
{
	int i;
    readfile();

    prins(start);

	  printf("\nMINIMUM SPINING TREE EDGES ARE :\n");
    for (i = 1; i < V; i++)
    {
        if(i<parent[i])
        printf("(%d,%d)\n",i, parent[i]);
        else
        printf("(%d,%d)\n",parent[i], i);
    }
    return 0;
}

void readfile()
{
  char filename[20];
  printf("\nEnter the filename : ");
  scanf("%s", filename);
	FILE *fptr;
    int u, v, weight;
	int success,r,w;
	int i = 0;
	fptr = fopen(filename, "r");

	if(fptr == NULL)
	{
		printf("********File didn't open properly**********\n");
		return;
	}
	else
	{
		success = fscanf(fptr, "%d", &V);
		printf("\n%d\n",V);
    success = fscanf(fptr, "%d", &E);
		printf("%d\n",E);

		for (i = 0; i < V; i++)
		{
    		head[i] = NULL;
 	 	}

		for(i=1; i<=E; i++)
		{
      		fscanf(fptr, "%d", &u);
      		fscanf(fptr, "%d", &v);
      		fscanf(fptr, "%d", &weight);
      		printf("%d %d %d\n",u,v,weight);
      		insertadjver(u,v,weight);
          insertadjver(v,u,weight);
		}
	}
  fclose(fptr);
}



void insertadjver(int src,int des, int weight)
{
    adjlistnode *p,*q;

    q=newadjlistnode(des, weight);

    if(head[src]==NULL)
        head[src]=q;
    else
    {
        p=head[src];

        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

adjlistnode *newadjlistnode(int vertex, int weight)
{
	adjlistnode *p;
	p = (adjlistnode *)malloc(sizeof(adjlistnode));
	p->vertex = vertex;
	p->weight = weight;
	p->next = NULL;
	return(p);
}

heapnode *newheapnode(int vertex, int cost)
{
	heapnode *p;
	p = (heapnode *)malloc(sizeof(heapnode));
	p->vertex = vertex;
	p->cost = cost;
	return(p);
}

heap *Buildheap(int maxsize)
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->currentsize = 0;
    h->maxsize = maxsize;
    h->pos = (int *)malloc(maxsize*sizeof(int));
    h->array = (heapnode **)malloc(maxsize*sizeof(heapnode *));
	return(h);
}

void prins(int start)
{
	int i;
	heap *h = Buildheap(V);
	for(i = 0; i<V; i++)
	{
    parent[i] = INT_MAX;
		cost[i] = INT_MAX;
		h->array[i]= newheapnode(i,cost[i]);
		h->currentsize++;
		h->pos[i] = i;
	}
	cost[start] = 0;
  h->array[start]->cost = cost[start];
  parent[start] = start;
	decreaseKey(h, start, cost[start]);

	while(h->currentsize!=0)
    {
        heapnode* tempheapnode = extractMin(h);
        int u = tempheapnode->vertex;
        adjlistnode *p = head[u];
        while (p != NULL)
        {
            int v = p->vertex;
            if (p->weight < cost[v] && cost[u] != INT_MAX)
            {
                cost[v] = p->weight;
                decreaseKey(h, v, cost[v]);
                parent[v] = u;
            }
            p= p->next;
        }
    }
}

void decreaseKey(heap* h, int v, int cost)
{
    int i = h->pos[v];
    h->array[i]->cost = cost;
    while ( (i!= 0) && h->array[i]->cost < h->array[(i - 1) / 2]->cost)
    {
        h->pos[h->array[i]->vertex] = (i-1)/2;
        h->pos[h->array[(i-1)/2]->vertex] = i;
        swap(&h->array[i],  &h->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void swap( heapnode**p, heapnode**q)
{
    heapnode *temp = *p;
    *p = *q;
    *q = temp;
}

heapnode *extractMin(heap *h)
{
	int i;
    heapnode *minHeapnode, *lastHeapnode;
    minHeapnode = h->array[0];
	lastHeapnode = h->array[h->currentsize-1];
	h->array[0] = lastHeapnode;
	h->array[h->currentsize-1] = minHeapnode;

	h->pos[lastHeapnode->vertex] = 0;
	h->pos[minHeapnode->vertex] = h->currentsize-1;

	h->currentsize--;

	minHeapify(h,0);


    return(minHeapnode);
}

void minHeapify(heap *h, int now)
{
  int child;

  while((now*2+2) <= (h->currentsize))
  {
	child = now*2 + 1;
	if (child != h->currentsize-1 && (h->array[child+1])->cost < (h->array[child])->cost)
  	{
  	  child++;
  	}

  	if((h->array[now])->cost > (h->array[child])->cost)
  	{
		h->pos[h->array[now]->vertex] = child;
		h->pos[h->array[child]->vertex] = now;

		swap(&h->array[now], &h->array[child] );
	}
	else
	{
		return;
	}
	now = child;
  }
}