// @Author:			jerry
// @Date:			Wed Jun 22 14:33:42 CST 2022
// @Description:	Interface of unionfind

#ifndef _IUNIONFIND_H_
#define _IUNIONFIND_H_
#include <iostream>
#include <vector>

namespace graph {
class IUnionFind {
public:
	virtual int size() const  = 0;
	virtual void union_set(int p, int q) = 0;	
	virtual bool is_conn(int p, int q) const = 0;
};
}




#endif // _IUNIONFIND_H_
