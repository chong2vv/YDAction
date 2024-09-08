//
//  YDAction.h
//  YDAction
//
//  Created by 王远东 on 2024/9/6.
//  Copyright © 2024 wangyuandong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define CLS(cls) NSStringFromClass((cls))
#define ACT(s) NSStringFromSelector((s))

@interface YDAction : NSObject

@property (nonatomic, strong) NSString *classMethod;
@property (nonatomic, strong) NSMutableDictionary  *parameters;
// state
@property (nonatomic, strong) NSString *toState;

+ (YDAction *)classMethod:(NSString *)classMethod;
+ (YDAction *)classMethod:(NSString *)classMethod parameters:(NSMutableDictionary *) parameters;
+ (YDAction *)classMethod:(NSString *)classMethod parameters:(NSMutableDictionary *)parameters toState:(NSString *)toState;

// Chain helper
+ (YDAction *(^)(NSString *))clsmtd; // 类和方法
+ (YDAction *(^)(NSString *))cls;    // 类
- (YDAction *(^)(NSString *))mtd;    // 方法
- (YDAction *(^)(NSMutableDictionary *))pa; // 可选：参数
- (YDAction *(^)(NSString *))toSt;   // 可选：更改状态

// 能在编译期检查类和方法的方法
+ (YDAction *(^)(Class))clas;    // 类
- (YDAction *(^)(SEL))mted;    // 方法

@end

NS_ASSUME_NONNULL_END
