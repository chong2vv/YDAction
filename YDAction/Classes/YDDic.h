//
//  YDDic.h
//  YDAction
//
//  Created by 王远东 on 2024/9/6.
//  Copyright © 2024 wangyuandong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YDDic : NSObject

+ (YDDic *)create;

- (YDDic *(^)(NSString *))key;
- (YDDic *(^)(id))val;
- (NSMutableDictionary *)done;

@end

NS_ASSUME_NONNULL_END
