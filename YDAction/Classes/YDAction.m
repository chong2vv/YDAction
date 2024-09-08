//
//  YDAction.m
//  YDAction
//
//  Created by 王远东 on 2024/9/6.
//  Copyright © 2024 wangyuandong. All rights reserved.
//

#import "YDAction.h"

@interface YDAction ()

@property (nonatomic, strong) NSString *chainCls;

@end

@implementation YDAction

+ (YDAction *)classMethod:(NSString *)classMethod {
    return [YDAction classMethod:classMethod parameters:nil];
}

+ (YDAction *)classMethod:(NSString *)classMethod parameters:(NSMutableDictionary *)parameters {
    return [YDAction classMethod:classMethod parameters:parameters toState:nil];
}

+ (YDAction *)classMethod:(NSString *)classMethod parameters:(NSMutableDictionary *)parameters toState:(NSString *)toState {
    YDAction *act = [[YDAction alloc] init];
    act.classMethod = classMethod;
    act.parameters = parameters;
    act.toState = toState;
    return act;
}

// Chain Helper
+ (YDAction *(^)(NSString *))clsmtd {
    return ^YDAction *(NSString *clsmtd) {
        YDAction *act = [[YDAction alloc] init];
        act.classMethod = clsmtd;
        return act;
    };
}

+ (YDAction *(^)(NSString *))cls {
    return ^YDAction *(NSString *cls) {
        YDAction *act = [[YDAction alloc] init];
        act.chainCls = cls;
        return act;
    };
}

- (YDAction *(^)(NSString *))mtd {
    return ^YDAction *(NSString *mtd) {
        self.classMethod = [NSString stringWithFormat:@"%@ %@",self.chainCls, mtd];
        return self;
    };
}

- (YDAction *(^)(NSMutableDictionary *))pa {
    return ^YDAction *(NSMutableDictionary *pa) {
        self.parameters = pa;
        return self;
    };
}

- (YDAction *(^)(NSString *))toSt {
    return ^YDAction *(NSString *toSt) {
        self.toState = toSt;
        return self;
    };
}

// 能在编译期检查的方法
+ (YDAction *(^)(Class))clas {
    return ^YDAction *(Class clas) {
        YDAction *act = [[YDAction alloc] init];
        act.chainCls = CLS(clas);
        return act;
    };
}

- (YDAction *(^)(SEL))mted {
    return ^YDAction *(SEL mted) {
        NSString *selStr = ACT(mted);
        NSString *clearSelStr = [selStr substringToIndex:([selStr length]-1)];
        self.classMethod = [NSString stringWithFormat:@"%@ %@",self.chainCls, clearSelStr];
        return self;
    };
}
@end
