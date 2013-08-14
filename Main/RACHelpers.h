//
//  RACHelpers.h
//  BrynKit-RACHelpers
//
//  Created by bryn austin bellomy on 3.13.13.
//  Copyright (c) 2013 bryn austin bellomy. All rights reserved.
//

//#import "Pods-environment.h"
//
//#if COCOAPODS_VERSION_MAJOR_ReactiveCocoa == 1 && COCOAPODS_VERSION_MINOR_ReactiveCocoa == 9 && COCOAPODS_VERSION_PATCH_ReactiveCocoa == 6
//#   define REACTIVECOCOA_1_9_6
//#else
//#   define REACTIVECOCOA_2_0_DEV
//#endif



#import <ReactiveCocoa/ReactiveCocoa.h>

//
// guess users have to manually define this for now
//
#if defined(REACTIVECOCOA_2_0_DEV)
#   import <ReactiveCocoa/RACTargetQueueScheduler.h>
#else
#   import <ReactiveCocoa/RACQueueScheduler.h>
#endif


#define RACDefaultUnit RACUnit.defaultUnit
#define RACSignalBox(x) [RACSignal return:(x)]


@interface RACSignal (BrynKit)

- (RACSignal *) onMainThreadScheduler;
- (RACDisposable *)then:(void (^)(void))completedBlock;

@end



@interface RACScheduler (BrynKit)

+ (RACDisposable *) onMainThread:(dispatch_block_t)block;

@end



@interface RACQueueScheduler (BrynKit_RACHelpers)

+ (instancetype) schedulerForQueue: (dispatch_queue_t)queue;

@end



@interface RACSubject (BrynKit_RACHelpers)

- (void) bk_sendUnit;
- (void) bk_sendUnitAndComplete;
- (void) bk_sendNextAndComplete:(id)nextObject;

@end



@interface RACStream (BrynKit_RACHelpers)

- (instancetype) notNil;
- (instancetype) notNilOrRACTupleNil;
- (instancetype) notEmpty;
- (instancetype) filterGreaterThanZero;
- (instancetype) filterZeroOrGreater;
- (instancetype) assertIsKindOfClass:(Class)klass;
- (instancetype) assertNotNilAndIsKindOfClass:(Class)klass;
- (instancetype) mapFromFloat32:(id (^)(Float32 value))block;
- (instancetype) mapFromFloat64:(id (^)(Float64 value))block;
- (instancetype) mapFromInteger:(id (^)(NSInteger value))block;
- (instancetype) mapFromUnsignedInteger:(id (^)(NSUInteger value))block;
- (instancetype) mapFromCGRect:(id (^)(CGRect value))block;
- (instancetype) mapFromBool:(id (^)(BOOL value))block;
- (instancetype) pluck:(NSString *)key;

@end

@interface RACStream (BrynKit_RCLHelpers)

- (instancetype) filterCGRectNull;
- (instancetype) filterCGRectInfinite;
- (instancetype) filterCGRectZero;
- (instancetype) filterCGRectIsEmpty;
- (instancetype) filterNonpositiveCGRects;

@end



@interface RACSignal (BrynKit_RACHelpers_BetterLogging)

- (instancetype) lllogAll;
- (instancetype) lllogNext;
- (instancetype) lllogError;
- (instancetype) lllogCompleted;

@end



@interface NSObject (BrynKit_RACHelpers)

- (BOOL) isNotNilAndNotRACTupleNil;

@end





