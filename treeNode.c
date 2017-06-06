
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
        struct TreeNode *left;
	    struct TreeNode *right;
	        TreeNode(int x) :
		        val(x), left(NULL), right(NULL)
			    {
			        }
				};

				//反序列号二叉树
				void Serialize(TreeNode *root,string &s)
				{
				    if(root!=NULL)
				        {
					        stringstream sstream;
						        sstream<<root->val;
							        string temp;
								        sstream>>temp;
									        s=s+temp+',';
										        Serialize(root->left,s);
											        Serialize(root->right,s);
												    }
												        else
													    {
													            s=s+"#,";
														        }
															}
															char * Serialize(TreeNode *root)
															{
															    string res;
															        Serialize(root,res);
																    char * fuck=new char[res.size()+1];
																        int i=0;
																	    for(; i<res.size(); i++)
																	        {
																		        fuck[i]=res[i];
																			    }
																			        i--;
																				    while(i>=0 && (res[i]==',' || res[i]<='#') )
																				        {
																					        i--;
																						    }
																						        i++;
																							    fuck[i++]='\0';
																							        return fuck;
																								}

																								//序列号二叉树
																								TreeNode* Deserialize(char *str,int &str_index)
																								{
																								    if(str==NULL||str_index>=strlen(str))
																								        {
																									        return NULL;
																										    }

																										        if(str[str_index]==',')str_index++;

																											    if(str[str_index]=='#')
																											        {
																												        str_index++;
																													        return NULL;
																														    }
																														        int num=0;
																															    while(str[str_index]>='0'&&str[str_index]<='9')
																															        {
																																        num=num*10+(str[str_index]-'0');
																																	        str_index++;
																																		    }
																																		        TreeNode *root=new TreeNode(num);
																																			    root->left=Deserialize(str,str_index);
																																			        root->right=Deserialize(str,str_index);
																																				    return root;
																																				    }
																																				    TreeNode* Deserialize(char *str)
																																				    {
																																				        int str_index=0;
																																					    TreeNode* root=Deserialize(str,str_index);
																																					        return root;
																																						}

																																						//求二叉树的深度
																																						int treeDepth(TreeNode *root)
																																						{
																																						    if(root==NULL)
																																						            return 0;
																																							        int left=treeDepth(root->left);
																																								    int right=treeDepth(root->right);
																																								        return (left>right)?left+1:right+1;
																																									}

																																									//判断二叉树是不是平衡二叉树，平衡二叉树是指在二叉树中任意节点的左右子树的深度不超过1
																																									bool isBlance(TreeNode* root)
																																									{
																																									    if(root==NULL)
																																									            return true;
																																										        int left=treeDepth(root->left);
																																											    int right=treeDepth(root->right);
																																											        int dif=left-right;
																																												    if(dif>1||dif<-1)
																																												            return false;
																																													        return isBlance(root->left)&&isBlance(root->right);
																																														}

																																														bool dfs(TreeNode *left,TreeNode * right)
																																														{
																																														    if(left!=NULL && right!=NULL && left->val==right->val)
																																														        {
																																															        return dfs(left->left,right->right)&&dfs(left->right,right->left);
																																																    }
																																																        else if(left==NULL && right==NULL)
																																																	    {
																																																	            return true;
																																																		        }
																																																			    return false;
																																																			    }
																																																			    bool isSymmetrical(TreeNode* root)
																																																			    {
																																																			        if(root==NULL) return true;
																																																				    return dfs(root->left,root->right);
																																																				    }


																																																				    //二叉树的子结构
																																																				    bool ok(TreeNode* pRoot1, TreeNode* pRoot2)
																																																				    {
																																																				        if(pRoot1==NULL && pRoot2==NULL)
																																																					    {
																																																					            return true;
																																																						        }
																																																							    else if(pRoot1!=NULL && pRoot2==NULL)
																																																							        {
																																																								        return true;
																																																									    }
																																																									        else if(pRoot1==NULL && pRoot2!=NULL)
																																																										    {
																																																										            return false;
																																																											        }
																																																												    if(pRoot1->val==pRoot2->val)
																																																												        {
																																																													        return ok(pRoot1->left,pRoot2->left) && ok(pRoot1->right,pRoot2->right);
																																																														    }

																																																														        return false;
																																																															}
																																																															bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
																																																															{
																																																															    if(pRoot2==NULL) return false;

																																																															        stack<TreeNode *>s;
																																																																    TreeNode *pCur=pRoot1;
																																																																        while(pCur!=NULL ||!s.empty())
																																																																	    {
																																																																	            while(pCur!=NULL)
																																																																		            {

																																																																			                if( ok(pCur, pRoot2) )
																																																																					            {
																																																																						                    return true;
																																																																								                }

																																																																										            s.push(pCur);
																																																																											                pCur=pCur->left;

																																																																													        }
																																																																														        pCur=s.top();
																																																																															        s.pop();
																																																																																        pCur=pCur->right;
																																																																																	    }
																																																																																	        return false;
																																																																																		}

																																																																																		//二叉树的镜像
																																																																																		void Mirror(TreeNode *pRoot)
																																																																																		{
																																																																																		    if(pRoot==NULL) return;
																																																																																		        TreeNode *temp;
																																																																																			    swap(pRoot->left,pRoot->right);
																																																																																			        Mirror(pRoot->left);
																																																																																				    Mirror(pRoot->right);
																																																																																				    }

																																																																																				    /*
																																																																																				        _30_
																																																																																					   /    \
																																																																																					     10    20
																																																																																					      /     /  \
																																																																																					      50    45  35

																																																																																					      前序遍历得到下面
																																																																																					      30,10,50,#,#,#,20,45,#,#,35,#,#


																																																																																					          _30_
																																																																																						     /    \
																																																																																						       10    20
																																																																																						        /     /  \
																																																																																							50    45  35
																																																																																							            \
																																																																																								                70
																																																																																										              \
																																																																																											                    55

																																																																																													    前序遍历得到下面
																																																																																													    30,10,50,#,#,#,20,45,#,#,35,#,70,#,55
																																																																																													    */
																																																																																													    /*
																																																																																													        _30_
																																																																																														   /    \
																																																																																														     10    10
																																																																																														      /  \  /  \
																																																																																														      50  4545  50

																																																																																														      前序遍历得到下面
																																																																																														      30,10,50,#,#,45,#,#,10,45,#,#,50,#,#
																																																																																														      */
																																																																																														      /*
																																																																																														      前序遍历preorder traversal  根左右
																																																																																														      后序遍历postorder traversal 左右跟
																																																																																														      中序遍历inorder traversal
																																																																																														      */

																																																																																														      /*
																																																																																														          _20_
																																																																																															     /    \
																																																																																															       19    28
																																																																																															        /     /  \
																																																																																																18    25  29
																																																																																																            \
																																																																																																	                50
																																																																																																			              \
																																																																																																				                    55

																																																																																																						    前序遍历得到下面
																																																																																																						    20,19,18,#,#,#,28,25,#,#,29,#,50,#,55
																																																																																																						    */

																																																																																																						    //前序遍历
																																																																																																						    vector<int> preorder(TreeNode* root)
																																																																																																						    {
																																																																																																						        vector<int> res;
																																																																																																							    if(root==NULL)
																																																																																																							        {
																																																																																																								        return res;
																																																																																																									    }

																																																																																																									        stack<TreeNode *> s;
																																																																																																										    TreeNode *pCur=root;
																																																																																																										        while(pCur!=NULL||!s.empty())
																																																																																																											    {
																																																																																																											            while(pCur!=NULL)
																																																																																																												            {
																																																																																																													                res.push_back(pCur->val);
																																																																																																															            s.push(pCur);
																																																																																																																                pCur=pCur->left;
																																																																																																																		        }
																																																																																																																			        pCur=s.top();
																																																																																																																				        s.pop();
																																																																																																																					        pCur=pCur->right;
																																																																																																																						    }
																																																																																																																						        return res;
																																																																																																																							}

																																																																																																																							vector<int> inorder(TreeNode * root)
																																																																																																																							{
																																																																																																																							    vector<int> res;
																																																																																																																							        if(root==NULL) return res;

																																																																																																																								    stack<TreeNode *> s;
																																																																																																																								        TreeNode * pCur=root;
																																																																																																																									    while(pCur!=NULL || !s.empty())
																																																																																																																									        {

																																																																																																																										        while(pCur!=NULL)
																																																																																																																											        {
																																																																																																																												            s.push(pCur);
																																																																																																																													                pCur=pCur->left;
																																																																																																																															        }
																																																																																																																																        pCur=s.top();
																																																																																																																																	        s.pop();
																																																																																																																																		        res.push_back(pCur->val);
																																																																																																																																			        pCur=pCur->right;
																																																																																																																																				    }
																																																																																																																																				        return res;

																																																																																																																																					}

																																																																																																																																					vector<int> postorder(TreeNode* root)
																																																																																																																																					{
																																																																																																																																					    vector<int> res;
																																																																																																																																					        if(root==NULL) return res;
																																																																																																																																						    /*
																																																																																																																																						        一个节点有三个状态State：
																																																																																																																																							    1、没有访问过 T.end()
																																																																																																																																							        2、去过右边 ‘L’
																																																																																																																																								    3、去过右边 ‘R’
																																																																																																																																								        */
																																																																																																																																									    map<TreeNode*,char> visitState;
																																																																																																																																									        stack<TreeNode *>s;
																																																																																																																																										    TreeNode* pCur=root;
																																																																																																																																										        do
																																																																																																																																											    {
																																																																																																																																											            while(pCur!=NULL && visitState.find(pCur)==visitState.end())
																																																																																																																																												            {
																																																																																																																																													                s.push(pCur);
																																																																																																																																															            visitState[pCur]='L';
																																																																																																																																																                pCur=pCur->left;
																																																																																																																																																		        }
																																																																																																																																																			        pCur=s.top();
																																																																																																																																																				        if(visitState[pCur]=='L')
																																																																																																																																																					        {
																																																																																																																																																						            visitState[pCur]='R';
																																																																																																																																																							                pCur=pCur->right;
																																																																																																																																																									        }
																																																																																																																																																										        else if(visitState[pCur]=='R')
																																																																																																																																																											        {
																																																																																																																																																												            res.push_back(pCur->val);
																																																																																																																																																													                s.pop();
																																																																																																																																																															        }
																																																																																																																																																																    }
																																																																																																																																																																        while(!s.empty());
																																																																																																																																																																	    return res;
																																																																																																																																																																	    }
																																																																																																																																																																	    vector<int> postorder2(TreeNode* root)
																																																																																																																																																																	    {
																																																																																																																																																																	        vector<int> res;
																																																																																																																																																																		    if(root==NULL) return res;
																																																																																																																																																																		        TreeNode * pCur=NULL, *pLast=NULL;
																																																																																																																																																																			    stack<TreeNode *> s;
																																																																																																																																																																			        pCur=root;
																																																																																																																																																																				    while(pCur!=NULL  )
																																																																																																																																																																				        {
																																																																																																																																																																					        s.push(pCur);
																																																																																																																																																																						        pCur=pCur->left;
																																																																																																																																																																							    }
																																																																																																																																																																							        while(!s.empty())
																																																																																																																																																																								    {
																																																																																																																																																																								            pCur=s.top();
																																																																																																																																																																									            //左右子树为空，或者上次的输出的节点为右
																																																																																																																																																																										            if(pCur->right==NULL ||pCur->right==pLast)
																																																																																																																																																																											            {
																																																																																																																																																																												                res.push_back(pCur->val);
																																																																																																																																																																														            pLast=pCur;
																																																																																																																																																																															                s.pop();
																																																																																																																																																																																	        }
																																																																																																																																																																																		        else
																																																																																																																																																																																			        {
																																																																																																																																																																																				            pCur=pCur->right;
																																																																																																																																																																																					                while(pCur!=NULL  )
																																																																																																																																																																																							            {
																																																																																																																																																																																								                    s.push(pCur);
																																																																																																																																																																																										                    pCur=pCur->left;
																																																																																																																																																																																												                }
																																																																																																																																																																																														        }
																																																																																																																																																																																															    }
																																																																																																																																																																																															    }


																																																																																																																																																																																															    template<class T>
																																																																																																																																																																																															    void print_vector(vector<int> input)
																																																																																																																																																																																															    {
																																																																																																																																																																																															        for(auto it=input.begin(); it!=input.end(); ++it)
																																																																																																																																																																																																    {
																																																																																																																																																																																																            cout<<*it<<" ";
																																																																																																																																																																																																	        }
																																																																																																																																																																																																		    cout<<endl;
																																																																																																																																																																																																		    }

																																																																																																																																																																																																		    //前序遍历+中序遍历 ==》构建一棵树
																																																																																																																																																																																																		    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
																																																																																																																																																																																																		    {
																																																																																																																																																																																																		        if(pre.size()==0) return NULL;
																																																																																																																																																																																																			    if(pre.size()==1) return new TreeNode(vin[0]);

																																																																																																																																																																																																			        int rootVal=pre[0];
																																																																																																																																																																																																				    TreeNode* root=new TreeNode(rootVal);

																																																																																																																																																																																																				        vector<int> pre_left,pre_right,vin_right,vin_left;

																																																																																																																																																																																																					    //切割点的位置
																																																																																																																																																																																																					        int index=0;
																																																																																																																																																																																																						    for(int i=0; i<vin.size(); i++)
																																																																																																																																																																																																						        {
																																																																																																																																																																																																							        if(rootVal==vin[i])
																																																																																																																																																																																																								        {
																																																																																																																																																																																																									            index=i;
																																																																																																																																																																																																										                break;
																																																																																																																																																																																																												        }
																																																																																																																																																																																																													        vin_left.push_back(vin[i]);
																																																																																																																																																																																																														    }
																																																																																																																																																																																																														        for(int i=1; i<pre.size()&&i<=index; i++)
																																																																																																																																																																																																															    {
																																																																																																																																																																																																															            pre_left.push_back(pre[i]);
																																																																																																																																																																																																																        }
																																																																																																																																																																																																																	    for(int i=index+1; i<vin.size(); i++)
																																																																																																																																																																																																																	        {
																																																																																																																																																																																																																		        vin_right.push_back(vin[i]);
																																																																																																																																																																																																																			        pre_right.push_back(pre[i]);
																																																																																																																																																																																																																				    }
																																																																																																																																																																																																																				        root->left=reConstructBinaryTree(pre_left,vin_left);
																																																																																																																																																																																																																					    root->right=reConstructBinaryTree(pre_right,vin_right);
																																																																																																																																																																																																																					        return root;

																																																																																																																																																																																																																						}

																																																																																																																																																																																																																						//判断是否是 二叉搜索树的后序遍历
																																																																																																																																																																																																																						bool judge(vector<int>& a, int left, int right)
																																																																																																																																																																																																																						{
																																																																																																																																																																																																																						    if(left >= right) return true;
																																																																																																																																																																																																																						        int i = right;
																																																																																																																																																																																																																							    while(i > left && a[i - 1] > a[right]) --i;
																																																																																																																																																																																																																							        for(int j = i - 1; j >= left; --j)
																																																																																																																																																																																																																								    {
																																																																																																																																																																																																																								            if(a[j] > a[right])
																																																																																																																																																																																																																									                return false;
																																																																																																																																																																																																																											    }

																																																																																																																																																																																																																											        return judge(a, left, i - 1) && (judge(a, i, right - 1));
																																																																																																																																																																																																																												}
																																																																																																																																																																																																																												bool VerifySquenceOfBST(vector<int> a)
																																																																																																																																																																																																																												{
																																																																																																																																																																																																																												    if(!a.size())
																																																																																																																																																																																																																												            return false;
																																																																																																																																																																																																																													        return judge(a, 0, a.size() - 1);
																																																																																																																																																																																																																														}

																																																																																																																																																																																																																														//把二叉树变成双向链表
																																																																																																																																																																																																																														TreeNode* Convert(TreeNode* pRootOfTree)
																																																																																																																																																																																																																														{
																																																																																																																																																																																																																														    TreeNode* Last=NULL, *head=NULL;
																																																																																																																																																																																																																														        stack<TreeNode*> s;
																																																																																																																																																																																																																															    TreeNode *pCur=pRootOfTree;
																																																																																																																																																																																																																															        while( pCur!=NULL || !s.empty())
																																																																																																																																																																																																																																    {
																																																																																																																																																																																																																																            while(pCur!=NULL)
																																																																																																																																																																																																																																	            {
																																																																																																																																																																																																																																		                s.push(pCur);
																																																																																																																																																																																																																																				            pCur=pCur->left;
																																																																																																																																																																																																																																					            }
																																																																																																																																																																																																																																						            pCur=s.top();
																																																																																																																																																																																																																																							            if(Last==NULL)
																																																																																																																																																																																																																																								            {
																																																																																																																																																																																																																																									                head=pCur;
																																																																																																																																																																																																																																											            pCur->left=NULL;
																																																																																																																																																																																																																																												            }
																																																																																																																																																																																																																																													            else
																																																																																																																																																																																																																																														            {
																																																																																																																																																																																																																																															                Last->right=pCur;
																																																																																																																																																																																																																																																	            pCur->left=Last;
																																																																																																																																																																																																																																																		            }
																																																																																																																																																																																																																																																			            Last=pCur;
																																																																																																																																																																																																																																																				            pCur=pCur->right;
																																																																																																																																																																																																																																																					            s.pop();
																																																																																																																																																																																																																																																						        }
																																																																																																																																																																																																																																																							    return head;
																																																																																																																																																																																																																																																							    }

																																																																																																																																																																																																																																																							    int main()
																																																																																																																																																																																																																																																							    {
																																																																																																																																																																																																																																																							        //char *res="30,10,50,#,#,#,20,45,#,#,35,#,#";
																																																																																																																																																																																																																																																								    //char *res="30,10,50,#,#,#,20,45,#,#,35,#,70,#,55";
																																																																																																																																																																																																																																																								        //char *res="30,10,50,#,#,45,#,#,10,45,#,#,50,#,#";
																																																																																																																																																																																																																																																									    char *res="20,19,18,#,#,#,28,25,#,#,29,#,50,#,55";
																																																																																																																																																																																																																																																									        //根据序列得到二叉树，返回节点的根
																																																																																																																																																																																																																																																										    TreeNode* root=Deserialize(res);
																																																																																																																																																																																																																																																										        //重新序列化，并输出~
																																																																																																																																																																																																																																																											    res=Serialize(root);
																																																																																																																																																																																																																																																											        cout<<"重新的生成的序列为:"<<res<<endl;

																																																																																																																																																																																																																																																												    //求出二叉树的深度
																																																																																																																																																																																																																																																												        int depth=treeDepth(root);
																																																																																																																																																																																																																																																													    cout<<"二叉树的深度为:"<<depth<<endl;

																																																																																																																																																																																																																																																													        bool blance=isBlance(root);
																																																																																																																																																																																																																																																														    if(blance) cout<<"平衡二叉树"<<endl;
																																																																																																																																																																																																																																																														        else cout<<"不平衡二叉树"<<endl;

																																																																																																																																																																																																																																																															    bool symmetrical=isSymmetrical(root);
																																																																																																																																																																																																																																																															        if(symmetrical) cout<<"对称"<<endl;
																																																																																																																																																																																																																																																																    else cout<<"不对称"<<endl;

																																																																																																																																																																																																																																																																        vector<int> preorderTraversal;
																																																																																																																																																																																																																																																																	    preorderTraversal=preorder(root);
																																																																																																																																																																																																																																																																	        cout<<"前序遍历：";
																																																																																																																																																																																																																																																																		    print_vector<int>(preorderTraversal);

																																																																																																																																																																																																																																																																		        vector<int> inorderTraversal;
																																																																																																																																																																																																																																																																			    inorderTraversal=inorder(root);
																																																																																																																																																																																																																																																																			        cout<<"中序遍历：";
																																																																																																																																																																																																																																																																				    print_vector<int>(inorderTraversal);

																																																																																																																																																																																																																																																																				        vector<int> postorderTraversal;
																																																																																																																																																																																																																																																																					    postorderTraversal=postorder(root);
																																																																																																																																																																																																																																																																					        cout<<"后序遍历：";
																																																																																																																																																																																																																																																																						    print_vector<int>(postorderTraversal);
																																																																																																																																																																																																																																																																						        postorderTraversal=postorder2(root);
																																																																																																																																																																																																																																																																							    cout<<"后序遍历：";
																																																																																																																																																																																																																																																																							        print_vector<int>(postorderTraversal);

																																																																																																																																																																																																																																																																								    bool BST=VerifySquenceOfBST(postorderTraversal);
																																																																																																																																																																																																																																																																								        if(BST) cout<<"二叉收索树的后续遍历"<<endl;
																																																																																																																																																																																																																																																																									    else cout<<"不是二叉收索树的后续遍历"<<endl;

																																																																																																																																																																																																																																																																									        TreeNode *reRoot=reConstructBinaryTree(preorderTraversal,inorderTraversal);
																																																																																																																																																																																																																																																																										    res=Serialize(root);
																																																																																																																																																																																																																																																																										        cout<<"重建后-》重新的生成的序列为:"<<res<<endl;




																																																																																																																																																																																																																																																																											    bool sub=HasSubtree(root,root);
																																																																																																																																																																																																																																																																											        if(sub) cout<<"子结构"<<endl;
																																																																																																																																																																																																																																																																												    else cout<<"不是子结构"<<endl;

																																																																																																																																																																																																																																																																												        Mirror(root);
																																																																																																																																																																																																																																																																													    res=Serialize(root);
																																																																																																																																																																																																																																																																													        cout<<"对称后-》重新的生成的序列为:"<<res<<endl;

																																																																																																																																																																																																																																																																														    //-----------------------------
																																																																																																																																																																																																																																																																														        cout<<"----把二叉树转成双向链表-------"<<endl;
																																																																																																																																																																																																																																																																															    res="20,19,18,#,#,#,28,25,#,#,29,#,50,#,55";
																																																																																																																																																																																																																																																																															        TreeNode* root2=Deserialize(res);
																																																																																																																																																																																																																																																																																    TreeNode *link=Convert(root2);
																																																																																																																																																																																																																																																																																        while(link!=NULL){
																																																																																																																																																																																																																																																																																	        cout<<link->val<<"->";
																																																																																																																																																																																																																																																																																		        link=link->right;
																																																																																																																																																																																																																																																																																			    }
																																																																																																																																																																																																																																																																																			        cout<<endl;
																																																																																																																																																																																																																																																																																				    return 0;
																																																																																																																																																																																																																																																																																				    }
																																																																																																																																																																																																																																																																																				    
