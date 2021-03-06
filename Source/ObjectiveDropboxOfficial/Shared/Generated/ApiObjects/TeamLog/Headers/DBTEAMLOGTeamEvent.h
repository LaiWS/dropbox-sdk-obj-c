///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGActorLogInfo;
@class DBTEAMLOGAssetLogInfo;
@class DBTEAMLOGContextLogInfo;
@class DBTEAMLOGEventCategory;
@class DBTEAMLOGEventDetails;
@class DBTEAMLOGEventType;
@class DBTEAMLOGOriginLogInfo;
@class DBTEAMLOGParticipantLogInfo;
@class DBTEAMLOGTeamEvent;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `TeamEvent` struct.
///
/// An audit log event.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGTeamEvent : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The Dropbox timestamp representing when the action was taken.
@property (nonatomic, readonly) NSDate *timestamp;

/// The category that this type of action belongs to.
@property (nonatomic, readonly) DBTEAMLOGEventCategory *eventCategory;

/// The entity who actually performed the action.
@property (nonatomic, readonly) DBTEAMLOGActorLogInfo *actor;

/// The origin from which the actor performed the action including information
/// about host, ip address, location, session, etc. If the action was performed
/// programmatically via the API the origin represents the API client.
@property (nonatomic, readonly, nullable) DBTEAMLOGOriginLogInfo *origin;

/// Zero or more users and/or groups that are affected by the action. Note that
/// this list doesn't include any actors or users in context.
@property (nonatomic, readonly, nullable) NSArray<DBTEAMLOGParticipantLogInfo *> *participants;

/// Zero or more content assets involved in the action. Currently these include
/// Dropbox files and folders but in the future we might add other asset types
/// such as Paper documents, folders, projects, etc.
@property (nonatomic, readonly, nullable) NSArray<DBTEAMLOGAssetLogInfo *> *assets;

/// True if the action involved a non team member either as the actor or as one
/// of the affected users.
@property (nonatomic, readonly) NSNumber *involveNonTeamMember;

/// The user or team on whose behalf the actor performed the action.
@property (nonatomic, readonly) DBTEAMLOGContextLogInfo *context;

/// The particular type of action taken.
@property (nonatomic, readonly) DBTEAMLOGEventType *eventType;

/// The variable event schema applicable to this type of action, instantiated
/// with respect to this particular action.
@property (nonatomic, readonly) DBTEAMLOGEventDetails *details;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param timestamp The Dropbox timestamp representing when the action was
/// taken.
/// @param eventCategory The category that this type of action belongs to.
/// @param actor The entity who actually performed the action.
/// @param involveNonTeamMember True if the action involved a non team member
/// either as the actor or as one of the affected users.
/// @param context The user or team on whose behalf the actor performed the
/// action.
/// @param eventType The particular type of action taken.
/// @param details The variable event schema applicable to this type of action,
/// instantiated with respect to this particular action.
/// @param origin The origin from which the actor performed the action including
/// information about host, ip address, location, session, etc. If the action
/// was performed programmatically via the API the origin represents the API
/// client.
/// @param participants Zero or more users and/or groups that are affected by
/// the action. Note that this list doesn't include any actors or users in
/// context.
/// @param assets Zero or more content assets involved in the action. Currently
/// these include Dropbox files and folders but in the future we might add other
/// asset types such as Paper documents, folders, projects, etc.
///
/// @return An initialized instance.
///
- (instancetype)initWithTimestamp:(NSDate *)timestamp
                    eventCategory:(DBTEAMLOGEventCategory *)eventCategory
                            actor:(DBTEAMLOGActorLogInfo *)actor
             involveNonTeamMember:(NSNumber *)involveNonTeamMember
                          context:(DBTEAMLOGContextLogInfo *)context
                        eventType:(DBTEAMLOGEventType *)eventType
                          details:(DBTEAMLOGEventDetails *)details
                           origin:(nullable DBTEAMLOGOriginLogInfo *)origin
                     participants:(nullable NSArray<DBTEAMLOGParticipantLogInfo *> *)participants
                           assets:(nullable NSArray<DBTEAMLOGAssetLogInfo *> *)assets;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param timestamp The Dropbox timestamp representing when the action was
/// taken.
/// @param eventCategory The category that this type of action belongs to.
/// @param actor The entity who actually performed the action.
/// @param involveNonTeamMember True if the action involved a non team member
/// either as the actor or as one of the affected users.
/// @param context The user or team on whose behalf the actor performed the
/// action.
/// @param eventType The particular type of action taken.
/// @param details The variable event schema applicable to this type of action,
/// instantiated with respect to this particular action.
///
/// @return An initialized instance.
///
- (instancetype)initWithTimestamp:(NSDate *)timestamp
                    eventCategory:(DBTEAMLOGEventCategory *)eventCategory
                            actor:(DBTEAMLOGActorLogInfo *)actor
             involveNonTeamMember:(NSNumber *)involveNonTeamMember
                          context:(DBTEAMLOGContextLogInfo *)context
                        eventType:(DBTEAMLOGEventType *)eventType
                          details:(DBTEAMLOGEventDetails *)details;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `TeamEvent` struct.
///
@interface DBTEAMLOGTeamEventSerializer : NSObject

///
/// Serializes `DBTEAMLOGTeamEvent` instances.
///
/// @param instance An instance of the `DBTEAMLOGTeamEvent` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGTeamEvent` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGTeamEvent *)instance;

///
/// Deserializes `DBTEAMLOGTeamEvent` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGTeamEvent` API object.
///
/// @return An instantiation of the `DBTEAMLOGTeamEvent` object.
///
+ (DBTEAMLOGTeamEvent *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
