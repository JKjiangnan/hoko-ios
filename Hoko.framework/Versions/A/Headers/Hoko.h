//
//  Hoko.h
//  Version 0.1
//
//  Created by Hoko, S.A. on 23/07/14.
//  Copyright (c) 2014 Hoko, S.A. All rights reserved.
//

#import "HokoAnalytics.h"
#import "HokoDeeplinking.h"
#import "HokoPushNotifications.h"

#import "HKDeeplink.h"

/**
 *  Hoko is an easy-to-use Framework to handle Deeplinking, Push Notifications and the Analytics around them.
 *
 *  This is a simple drop-in class for handling incoming deeplinks and push notifications containing deeplinks.
 *  With the Hoko framework you can map routes to your view controllers, add handlers that trigger when
 *  deeplinks are the point of entry to your application.
 *
 *  Hoko includes three seperate modules:
 *  - HokoDeeplinking - handles every incoming deeplink, so long as it has been mapped
 *  - HokoPushNotifications - handles incoming notifications, so long as they contain a mapped deeplink
 *  - HokoAnalytics - handles the tracking of users and events to allow creation and evaluation of campaigns
 *  
 *  You should setup Hoko on your AppDelegate's application:didFinishLaunchingWithOptions:, by calling
 *  [Hoko setupWithToken:@"YOUR-API-TOKEN"].
 *
 */
@interface Hoko : NSObject

/**
 *  Setups all the Hoko module instances, logging and asynchronous networking queues.
 *  Setting up with a token will make sure you can take full advantage of the Hoko service,
 *  as you will be able to track everything through manual or automatic Analytics, which
 *  will be shown on your Hoko dashboards. Debug mode will automatically be enabled when
 *  your app is signed with a provisioning profile or you are running on the simulator. Debug
 *  mode serves the purpose of uploading the app icon and the mapped routes to the Hoko 
 *  backend service.
 *  <pre>
 *  [Hoko setupWithToken:@"YOUR-API-TOKEN"];
 *  </pre>
 *
 *  @param token Hoko service API key.
 */
+ (void)setupWithToken:(NSString *)token;

/**
 *  Setups all the Hoko module instances, logging and asynchronous networking queues.
 *  Setting up with a token will make sure you can take full advantage of the Hoko service,
 *  as you will be able to track everything through manual or automatic Analytics, which
 *  will be shown on your Hoko dashboards. Also sets the debug mode manually. Debug mode 
 *  serves the purpose of uploading the app icon and the mapped routes to the Hoko backend
 *  service.
 *  <pre>
 *  [Hoko setupWithToken:@"YOUR-API-TOKEN" debugMode:YES];
 *  </pre>
 *
 *  @param token Hoko service API key.
 */
+ (void)setupWithToken:(NSString *)token debugMode:(BOOL)debugMode;

/**
 *  The HokoDeeplinking module provides all the necessary APIs to map, handle and generate deeplinks.
 *  Different APIs as provided in order to be as versatile as your application requires them to be.
 *
 *  @return A reference to the HokoDeeplinking instance.
 */
+ (HokoDeeplinking *)deeplinking;

/**
 *  The HokoPushNotifications module provides all the necessary APIs to manage push notifications generated
 *  by the Hoko service. It provides also an abstraction between iOS<8.0 and iOS>=8.0 notification APIs for
 *  easier integration.
 *
 *  @return A reference to the HokoPushNotifications instance.
 */
+ (HokoPushNotifications *)pushNotifications;

/**
 *  The HokoAnalytics module provides all the necessary APIs to manage user and application behavior.
 *  Users should be identified to this module, as well as key events (e.g. sales, referrals, etc) in order
 *  to track campaign value and allow user segmentation.
 *
 *  @return A reference to the HokoAnalytics instance.
 */
+ (HokoAnalytics *)analytics;

/**
 *  Use this function to enable or disable logging from the Hoko SDK
 *
 *  @param verbose YES to enable logging, NO to disable.
 */
+ (void)setVerbose:(BOOL)verbose;

@end

