#include <iostream>
#include <vector>

typedef struct node {
	char data;
} Node;

typedef struct {
	Node *src, *dest;
	int weight;
} Edge;

class Graph {
	private :
		std::vector<Node*> nodes;
		std::vector<Edge*> edges;
		
	public : Node* getNode(char);	
	public : Edge* getEdges(Node*);	
	public :
		void addVertex(char, Node*, int);
		void connect(Node*, Node*, int);
};

int main() {
	Graph g;

	g.addVertex('A', NULL, 0);
	g.addVertex('B', NULL, 0);
	g.addVertex('C', g.getNode('A'), 0);
	g.addVertex('H', g.getNode('C'), 0);
	g.addVertex('k', g.getNode('B'), 0);
	g.addVertex('i', g.getNode('A'), 0);
	
	Node* tmp_node = g.getNode('A');
	Edge* tmp_edge = g.getEdges(tmp_node);

	std::cout << "A : " << tmp_edge->dest << std::endl; 	
	while(tmp_edge != NULL && tmp_edge->dest != NULL && tmp_edge->src != NULL) {
		Node* degre = tmp_edge->src != tmp_node ? tmp_edge->src : tmp_edge->dest;

		std::cout << "A => " << degre->data << std::endl;
	       	tmp_edge++;	
	}

	return 0;
}

void Graph::addVertex(char data, Node* src, int weigth) {
	if(src == NULL && nodes.empty()) {
		Node* newNode = new Node;
		newNode->data = data;
		nodes.push_back(newNode);
	}

	Node* node1 = src != NULL ? src : nodes[0];
	Node* newNode = new Node;
	Edge* newEdge = new Edge;

	newNode->data = data;
	newEdge->src = node1;
	newEdge->dest = newNode;
	
	nodes.push_back(newNode);
	edges.push_back(newEdge);
}

Node* Graph::getNode(char data) {
	Node* tmp = NULL;

	for(int i = 0; i < nodes.size(); i++) {
		if(nodes[i]->data == data) {
			tmp = nodes[i];
			break;
		}
	}

	return tmp;
}	

Edge* Graph::getEdges(Node* node) {
	Edge* found = NULL;
	int count = 0;
	
	for(int i = 0; i < edges.size(); i++) {
		if(edges[i]->dest == node || edges[i]->src == node) {
			found = (Edge* )(count > 0 ? realloc(found, sizeof(Edge) * (count + 1)) : malloc(sizeof(Edge)));
			found[count++] = *edges[i];
		}
	}

	if(found != NULL) {
		found = (Edge* )realloc(found, sizeof(Edge) * (count + 1));
		found[count].dest = NULL;
		found[count].src = NULL;
	}

	return found;
}

void connect(Node* src, Node* dest, int weigth) {
	Edge newEdge = new Edge;
	
}
