//
//  HKSampleQuery.h
//  HealthKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HealthKit.h>
#import <HealthKit/HKQuery.h>

#define HKObjectQueryNoLimit (0)

/*!
 @class         HKSampleQuery
 @abstract      A concrete subclass of HKQuery that provides an interface to retrieve HKSample objects.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKSampleQuery : HKQuery

/*!
 @property      limit
 @abstract      The maximum number of results the receiver will return upon completion.
 */
@property (readonly) NSUInteger limit;

/*!
 @property      sortDescriptors
 @abstract      An array of NSSortDescriptors.
 */
@property (readonly, copy) NSArray *sortDescriptors;

/*!
 @method        initWithSampleType:predicate:limit:sortDescriptors:resultsHandler:
 @abstract      Returns a query that will retrieve HKSamples matching the given predicate.
 
 @param         sampleType      The type of sample to retrieve.
 @param         predicate       The predicate which samples should match.
 @param         limit           The maximum number of samples to return.  Pass HKObjectQueryNoLimit for no limit.
 @param         sortDescriptors The sort descriptors to use to order the resulting samples.
 @param         resultsHandler  The block to invoke with results when the query has finished executing.
 */
- (instancetype)initWithSampleType:(HKSampleType *)sampleType
                         predicate:(NSPredicate *)predicate
                             limit:(NSUInteger)limit
                   sortDescriptors:(NSArray *)sortDescriptors
                    resultsHandler:(void(^)(HKSampleQuery *query, NSArray *results, NSError *error))resultsHandler;


@end
