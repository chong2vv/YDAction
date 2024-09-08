//
//  YDMediator.h
//  YDAction
//
//  Created by 王远东 on 2024/9/7.
//  Copyright © 2024 wangyuandong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YDAction.h"
#import "YDDic.h"

NS_ASSUME_NONNULL_BEGIN

@interface YDMediator : NSObject

/* ------- 解指令执行 ---------- */
- (void)eval:(NSString *)script;

/* ------- Reducer ------- */
// Reducer 下面几种是不同的调用写法，最终的执行是一致的。
- (id)dispatch:(YDAction *)action; // 可以设置更改当前状态
- (id)classMethod:(NSString *)classMethod;
- (id)classMethod:(NSString *)classMethod parameters:(NSDictionary *)parameters;
// helper
- (id (^)(YDAction *))dispatch;

/* ------- Middleware ------- */
// Middleware 当设置的方法执行时先执行指定的方法，可用于观察某方法的执行，然后通知其它 com 执行观察方法进行响应
- (void)middleware:(NSString *)whenClassMethod thenAddDispatch:(YDAction *)action;
// Middleware 链式写法支持
- (YDMediator *(^)(NSString *))middleware;
- (YDMediator *(^)(YDAction *))addMiddlewareAction;

/* ------- State ------- */
// State manager 状态管理
- (NSString *)currentState;
- (void)updateCurrentState:(NSString *)state;
// State 链式写法支持
- (YDMediator *(^)(NSString *))updateCurrentState;

/* ------- Observer ------- */
// Observer
- (void)observerWithIdentifier:(NSString *)identifier observer:(YDAction *)act;
- (void)notifyObservers:(NSString *)identifier;
// Observer 链式写法支持
- (YDMediator *(^)(NSString *))observerWithIdentifier;
- (YDMediator *(^)(YDAction *))addObserver;

/* --------- Factory ---------*/
- (void)factoryClass:(NSString *)fClass useFactory:(NSString *)factory;
// Factory 链式写法
- (YDMediator *(^)(NSString *))factoryClass;
- (YDMediator *(^)(NSString *))factory;

@end

NS_ASSUME_NONNULL_END
