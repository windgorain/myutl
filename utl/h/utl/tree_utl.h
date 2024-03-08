/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2010-1-13
* Description: 
* History:     
******************************************************************************/

#ifndef __TREE_UTL_H_
#define __TREE_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif 

typedef HANDLE TREE_HANDLE;

typedef struct TREE_NODE_ST
{
    DLL_NODE_S stLinkNode;  
    DLL_HEAD_S stChildNode; 
}TREE_NODE_S;

typedef struct {
    TREE_NODE_S root;
}TREE_CTRL_S;


#define TREE_IS_LEAF(pstNode)   (DLL_COUNT(&((pstNode)->stChildNode)) == 0 ? TRUE : FALSE)
#define TREE_IS_ROOT(pstNode)   (DLL_GET_HEAD(pstNode) == NULL ? TRUE : FALSE)
#define TREE_SCAN_SUBNODE(pstRoot, pstNode)  DLL_SCAN(&((pstRoot)->stChildNode), (pstNode))
#define TREE_SAFE_SCAN_SUBNODE(pstRoot, pstNode,pstNodeTmp)  DLL_SAFE_SCAN(&((pstRoot)->stChildNode), (pstNode),(pstNodeTmp))

typedef BS_WALK_RET_E (*PF_TREE_DepthScanNode)(IN TREE_NODE_S *pstNode, IN UINT ulDeepth, IN VOID *pUserHandle);
typedef BS_WALK_RET_E (*PF_TREE_DepthWalkNode)(IN TREE_NODE_S *pstNode, IN UINT ulDeepth, IN BOOL_T bIsBack, IN VOID * pUserHandle);

TREE_HANDLE Tree_Create();
VOID TREE_NodeInit(IN TREE_NODE_S *pstNode);
BS_STATUS TREE_AddNode(IN TREE_NODE_S *pstParent, IN TREE_NODE_S *pstChildNode);
BS_STATUS TREE_RemoveNode(IN TREE_NODE_S *pstNode);
TREE_NODE_S * TREE_GetParent(IN TREE_NODE_S *pstNode);


BS_WALK_RET_E TREE_DepthParentFirstWalk
(
    IN TREE_NODE_S *pstRoot,
    IN PF_TREE_DepthScanNode pfFunc,
    IN VOID *pUserHandle
);


BS_WALK_RET_E TREE_DepthChildFirstWalk
(
    IN TREE_NODE_S *pstRoot,
    IN PF_TREE_DepthScanNode pfFunc,
    IN VOID *pUserHandle
);


BS_WALK_RET_E TREE_DepthBackWalk
(
    IN TREE_NODE_S *pstRoot,
    IN PF_TREE_DepthWalkNode pfFunc,
    IN VOID *pUserHandle
);

#ifdef __cplusplus
    }
#endif 

#endif 


