#ifndef PROPAGATION_RULE_HH
#define PROPAGATION_RULE_HH


#include <string>
#include <unordered_map>


#include "clang/AST/ASTContext.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Lex/Lexer.h"
#include "macros.hh"
#include <iostream>
#include <nlohmann/json.hpp>



using namespace clang;
using namespace std;

class VariableRenamer : public RecursiveASTVisitor<VariableRenamer> {
public: 
    VariableRenamer(Rewriter &R, const unordered_map<string, string>& nm);
    bool VisitVarDecl(VarDecl *v);
    bool VisitDeclRefExpr(DeclRefExpr *e);

private: 
    Rewriter &rewriter;
    const unordered_map<string, string>& nameMap;  // old name -> new name
}; 

struct MemoryAccessInfo;
void to_json(nlohmann::json &j, const MemoryAccessInfo &info);


class BeyondAccessVisitor : public RecursiveASTVisitor<BeyondAccessVisitor> {
public: 
    BeyondAccessVisitor(ASTContext &C, Rewriter &R);
    ~BeyondAccessVisitor();
    vector<MemoryAccessInfo*> memberAccess;
    bool VisitBinaryOperator(BinaryOperator *expr);
    bool VisitArraySubscriptExpr(ArraySubscriptExpr *ase);
    bool VisitDeclRefExpr(DeclRefExpr *dref);
    nlohmann::json dumpAccessToJson();
private: 
    Rewriter &rewriter;
    ASTContext &context;
    unsigned getLineNumber(Expr *expr);
    bool isDeclArg(DeclRefExpr *dref);
    bool isExprPtr(DeclRefExpr *expr);
    bool isExprPtr(CStyleCastExpr *expr);
    bool isExprPtr(const CStyleCastExpr *expr);
    unsigned getTypeSizeInBytes(DeclRefExpr *dref);
    unsigned getTypeSizeInBytes(CStyleCastExpr *expr);
    unsigned getTypeSizeInBytesHelper(QualType qt);
    unsigned getPointeeSizeInBytes(DeclRefExpr *dref);
    unsigned getPointeeSizeInBytes(CStyleCastExpr *expr);
    unsigned getPointeeSizeInBytes(const CStyleCastExpr *expr);
    unsigned getPointeeSizeInBytesHelper(QualType qt);
    const CStyleCastExpr* getParentCastExpr(Expr *expr);
    MemoryAccessInfo* parse_addition(BinaryOperator *bo);
    pair<unsigned, string> getExprPointeeDetails(const Expr *expr);
    pair<unsigned, string> getExprPointeeDetails(BinaryOperator *bo);
    bool isAddSubMulDivBinaryOp(const Stmt* stmt);
}; 


struct CallsiteInfo;
void to_json(nlohmann::json &j, const CallsiteInfo &info);

class CallsiteVisitor : public RecursiveASTVisitor<CallsiteVisitor> {
public: 
    CallsiteVisitor(ASTContext &C, Rewriter &R);
    ~CallsiteVisitor();
    vector<CallsiteInfo*> callsitesInfo;
    bool VisitCallExpr(CallExpr *call);
    nlohmann::json dumpCallsitesToJson();
private: 
    Rewriter &rewriter;
    ASTContext &context;
    unsigned getLineNumber(Expr *expr);
}; 


struct VariableAssignmentInfo;
void to_json(nlohmann::json &j, const VariableAssignmentInfo &info);

class DataflowVisitor : public RecursiveASTVisitor<DataflowVisitor> {
public: 
    DataflowVisitor(ASTContext &C, Rewriter &R);
    ~DataflowVisitor();
    vector<VariableAssignmentInfo*> assignments;
    bool VisitBinaryOperator(BinaryOperator *bo);
    nlohmann::json dumpDataflowToJson();
private: 
    Rewriter &rewriter;
    ASTContext &context;
    unsigned getLineNumber(Expr *expr);
    bool isVariableOrArgument(DeclRefExpr *expr);
}; 




#endif