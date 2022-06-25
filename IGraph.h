// @Author:			jerry
// @Date:			Wed Jun 22 15:49:21 CST 2022
// @Description:	interface of adjtable and adjdictionary

#ifndef _IGRAPH_H_
#define _IGRAPH_H_

#include <iostream>
#include <vector>

namespace graph {
class IGraph {
public:
	virtual ~IGraph() { }; 
	virtual int get_vertex_num() const = 0;
	virtual int get_edge_num() const = 0;
	virtual bool has_edge(int, int) const = 0;
	virtual int degree(int a) const = 0;
	virtual std::vector<int> get_adj(int) const = 0;
};
}


#endif // _IGRAPH_H_


