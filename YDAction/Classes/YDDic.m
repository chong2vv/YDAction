//
//  YDDic.m
//  YDAction
//
//  Created by 王远东 on 2024/9/6.
//  Copyright © 2024 wangyuandong. All rights reserved.
//

#import "YDDic.h"

@interface YDDic ()

@property (nonatomic, strong) NSMutableDictionary *chainDic;
@property (nonatomic, strong) NSString *chainCurrentKey;

@end

@implementation YDDic

+ (YDDic *)create {
    return [[YDDic alloc] init];
}

// parameters
- (YDDic *(^)(NSString *))key {
    return ^YDDic *(NSString *pKey) {
        self.chainCurrentKey = pKey;
        return self;
    };
}
- (YDDic *(^)(id))val {
    return ^YDDic *(id pVal) {
        self.chainDic[self.chainCurrentKey] = pVal;
        return self;
    };
}
- (NSMutableDictionary *)done {
    NSMutableDictionary *re = [NSMutableDictionary dictionaryWithDictionary:self.chainDic];
    self.chainDic = [NSMutableDictionary new];
    return re;
}

// Getter
- (NSMutableDictionary *)chainDic {
    if (!_chainDic) {
        _chainDic = [NSMutableDictionary new];
    }
    return _chainDic;
}


@end
