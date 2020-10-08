define("modules/clean/react/growth/features/util",["require","exports","tslib","modules/core/browser","modules/clean/server_side_client_view_bridge","modules/clean/referrer_cleansing_redirect","modules/clean/react/growth/logging_util","modules/clean/react/growth/features/types","modules/clean/react/growth/util","modules/clean/react/growth/feature_tour_modal/feature_tour_modal_loader"],(function(e,t,n,a,o,r,c,u,l,i){"use strict";function s(e,t,n){var a=l.getActiveUserId();switch(n.onClickType){case u.OnClickType.OPEN_TAB_TO_APPLE_SUBSCRIPTION_HELP_PAGE:return function(){c.logCtaClick(e,t,c.CtaType.OPEN_EXTERNAL_LINK,{href:"https://support.apple.com/HT202039"},(function(){r.safe_open_tab_and_redirect("https://support.apple.com/HT202039")}))};case u.OnClickType.SHOW_FEATURE_TOUR_MODAL:return function(){n.moduleName&&a&&l.markModuleAsCompleted(a,n.moduleName),c.logCtaClick(e,t,c.CtaType.OPEN_MODAL,{modalType:u.ModalType.FEATURE_TOUR_MODAL}),i.renderFeatureTourModal(e)}}}function d(e,t,n,r,u,l){if(c.logCtaClick(t,n,c.CtaType.OPEN_EXTERNAL_LINK,{href:e}),o.GetPlatform()){var i=l?o.ViewManagementClose:void 0;u?o.OpenCredentialedBrowser(e,u,i):o.OpenUncredentialedBrowser(e,i)}else r?a.open_tab(e):a.redirect(e)}Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importStar(a),o=n.__importStar(o),r=n.__importStar(r),t.getOnClickHandler=s,t.getOnClickHandlerForCta=function(e,t,n,a){if(n.href||n.onClick||n.onClickType)return n.onClickType?s(e,t,n):n.onClick?n.onClick:function(){return d(n.href||"#",e,t,!1,a,!0)}},t.openHref=d})),define("modules/clean/react/growth/feature_tour_modal/constants",["require","exports","modules/clean/ts_utils","modules/clean/react/growth/features/types"],(function(e,t,n,a){"use strict";var o;Object.defineProperty(t,"__esModule",{value:!0}),(function(e){e.UPLOAD="upload",e.SHARING="sharing",e.ORGANIZING="organizing",e.HELP="help"})(o=t.TopicKey||(t.TopicKey={})),(function(e){e.LIST="list",e.SINGLE="single"})(t.TopicType||(t.TopicType={})),(function(e){e.IMAGE="image",e.VIDEO="video"})(t.VisualAssetType||(t.VisualAssetType={})),(function(e){e.CLOUD="cloud",e.ORCHID="orchid",e.WHEAT="wheat",e.WHITE="white"})(t.BackgroundColor||(t.BackgroundColor={})),t.getTopicKeys=function(e){switch(e){case a.ProjectType.NCCT_PLUS_TRIALS:case a.ProjectType.NCCT_PLUS_TRIALS_ENABLE_AUTO_CONVERT:case a.ProjectType.PLATFORM_PLUS_TRIALS_30D:case a.ProjectType.POT_OF_GOLD:case a.ProjectType.WEB_FAMILY_DIRECT:case a.ProjectType.WEB_PLUS_DIRECT:case a.ProjectType.WEB_PLUS_TRIALS:return[o.UPLOAD,o.ORGANIZING,o.SHARING,o.HELP];default:return n.enforceExhaustive(e)}}})),define("modules/clean/react/growth/feature_tour_modal/feature_tour_modal_loader",["require","exports","tslib","react","modules/clean/react/async/loadable","modules/clean/react/growth/feature_tour_modal/constants","modules/clean/react/growth/logging_util"],(function(e,t,n,a,o,r,c){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a);var u=o.Loadable({loader:function(){return new Promise((function(t,n){e(["modules/clean/react/growth/feature_tour_modal/components/feature_tour_modal"],t,n)})).then(n.__importStar).then((function(e){return e.FeatureTourModal}))}});t.renderFeatureTourModal=function(t,o,l){var i=r.getTopicKeys(t);return i.length?new Promise((function(t,n){e(["modules/clean/react/modal"],t,n)})).then(n.__importStar).then((function(e){e.Modal.showInstance(a.default.createElement(u,{topicKeys:i,className:o,handleDismiss:l,loggingProject:t,loggingComponentName:c.ComponentName.FEATURE_TOUR_MODAL}))})):null}})),define("modules/clean/react/growth/trials/types",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),(function(e){e.CANCEL_TRIAL_BIZ_INVITE="cancel_trial_biz_invite_modal",e.CANCEL_TRIAL_EXPECTATIONS="cancel_trial_expectations_modal",e.CANCEL_TRIAL_SURVEY="cancel_trial_survey_modal"})(t.ModalType||(t.ModalType={})),(function(e){e.GOOGLE_PLAY_TRIALS="google_play_trials",e.IOS_TRIALS="ios_trials",e.NCCT_PLUS_TRIALS="ncct_plus_trials",e.NCCT_PLUS_TRIALS_ENABLE_AUTO_CONVERT="ncct_plus_trials_enable_auto_convert",e.PLATFORM_PLUS_TRIALS_30D="platform_plus_trials_30d",e.RIGHTSIZING="rightsizing",e.WEB_PLUS_TRIALS="web_plus_trials"})(t.ProjectType||(t.ProjectType={})),(function(e){e[e.UNKNOWN=0]="UNKNOWN",e[e.TRANSITIONS_TRIAL=1]="TRANSITIONS_TRIAL",e[e.PLATFORM_TRIAL=2]="PLATFORM_TRIAL"})(t.TrialSource||(t.TrialSource={}))})),define("modules/clean/react/account_menu/account_menu",["require","exports","tslib","react","dig-components/layer","modules/clean/ajax_as_promised","modules/clean/analytics","modules/clean/api_v2/user_client","modules/clean/event_handler","modules/clean/react/account_menu/account_menu_types","modules/clean/react/account_menu/account_menu_util","modules/clean/react/account_menu/account_menu_view","modules/clean/web_timing_logger","modules/core/browser","modules/core/uri","modules/clean/chat/chat_client_factory"],(function(e,t,n,a,o,r,c,u,l,i,s,d,_,p,m,f){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a),p=n.__importStar(p);var h=(function(t){function h(e){var n=t.call(this,e)||this;return n.handleChatLink=function(){n.widgetId&&(f.ChatClientFactory.getClient().startSupportChat(n.widgetId),c.TeamsWebActionsLogger.log("chat_discoverability_account_menu_clicked"))},n.handleMenuSelection=function(e){switch(e){case i.AccountMenuSelectionOption.SETTINGS:p.redirect(s.SETTINGS_URL);break;case i.AccountMenuSelectionOption.INSTALL:s.handleInstallClick(),p.open_tab(s.INSTALL_URL);break;case i.AccountMenuSelectionOption.CHAT:n.handleChatLink();break;case i.AccountMenuSelectionOption.LOGOUT:p.redirect(s.getLogoutUrl())}},n.apiV2Client=new u.UserApiV2Client,n.state={accountPhotoUrl:n.props.user.photo_circle_url,showChatLink:!1,accountSpaceUsage:{currentStatus:i.AccountSpaceUsageStatus.NOT_APPLICABLE}},n}return n.__extends(h,t),h.prototype.componentDidMount=function(){return n.__awaiter(this,void 0,void 0,(function(){return n.__generator(this,(function(t){switch(t.label){case 0:return this.attachEventListeners(),[4,_.waitForTTI()];case 1:return t.sent(),this.getQuotaData(),this.getChatVariants(),[4,new Promise((function(t,n){e(["modules/clean/account/timezone_detection"],t,n)})).then(n.__importStar)];case 2:return t.sent().checkTimezone(),[2]}}))}))},h.prototype.componentWillUnmount=function(){this.events.removeAll()},h.prototype.attachEventListeners=function(){var e=this;this.events=new l.EventHandler,this.events.on(document,"db:account_photo:photo_set",(function(t,n){var a=m.URI.parse(n.saved_photo_url).updateQuery({size:"64x64"}).toString();e.setState({accountPhotoUrl:a})})),this.events.on(document,"db:account_photo:photo_deleted",(function(){e.setState({accountPhotoUrl:void 0})}))},h.prototype.getQuotaData=function(){return n.__awaiter(this,void 0,void 0,(function(){var e,t,a,o,r,c;return n.__generator(this,(function(n){switch(n.label){case 0:e=this.props.user,this.setState({accountSpaceUsage:{currentStatus:i.AccountSpaceUsageStatus.LOADING}}),n.label=1;case 1:return n.trys.push([1,3,,4]),t=this.apiV2Client.ns("users").rpc("get_space_usage",void 0,{subjectUserId:e.id}),a=this.apiV2Client.ns("users").rpc("get_plan_info",{account_id:e.account_id},{subjectUserId:e.id}),[4,Promise.all([t,a])];case 2:return o=n.sent(),r=o[0],c=o[1],this.setState({accountSpaceUsage:s.getAccountSpaceUsage(r,c)}),[3,4];case 3:return n.sent(),this.setState({accountSpaceUsage:{currentStatus:i.AccountSpaceUsageStatus.NOT_APPLICABLE}}),[3,4];case 4:return[2]}}))}))},h.prototype.getChatVariants=function(){return n.__awaiter(this,void 0,void 0,(function(){var e,t;return n.__generator(this,(function(n){switch(n.label){case 0:return e=this.props.user,[4,r.SilentBackgroundRequest({url:"/portkey_chat_discoverability_variant",dataType:"json",subject_user:e.id})];case 1:return(t=n.sent())&&(this.widgetId=t.widgetId,this.setState({showChatLink:"V1"===t.variant&&!!this.widgetId})),[2]}}))}))},h.prototype.render=function(){var e=this.state,t=e.accountPhotoUrl,n=e.showChatLink,r=e.accountSpaceUsage,c=this.props,u=c.showInstallLink,l=c.viewer,s=c.user;return a.default.createElement(o.LayerContext.Provider,{value:500},a.default.createElement(d.AccountMenuView,{user:s,viewer:l,accountPhotoUrl:t,showChatLink:n,showInstallLink:!!u,onMenuSelection:this.handleMenuSelection,accountSpaceUsage:r,quotaBarMinimumBreakpoint:i.AccountMenuQuotaBarBreakpoints.STANDARD}))},h.defaultProps={showInstallLink:!0},h})(a.default.Component);t.AccountMenu=h})),define("modules/clean/react/account_menu/account_menu_quota_bar",["require","exports","tslib","react","dig-components/icons","dig-components/icons/src/ui-icon/line/warning","dig-components/typography","modules/clean/display_format","modules/clean/react/account_menu/account_menu_types","modules/clean/react/account_menu/account_menu_upgrade_button","modules/clean/react/account_menu/account_menu_util","modules/core/i18n"],(function(e,t,n,a,o,r,c,u,l,i,s,d){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a),t.AccountMenuQuotaBar=function(e){var t=e.accountSpaceUsage;if(t.currentStatus===l.AccountSpaceUsageStatus.LOADING)return null;var n=t.used,o=t.allocated;return a.default.createElement(_,{used:n,allocated:o,quotaBarMinimumBreakpoint:e.quotaBarMinimumBreakpoint,user:e.user,viewer:e.viewer})};var _=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return n.__extends(t,e),t.prototype.render=function(){var e=this.props,t=e.used,n=e.allocated,_=e.quotaBarMinimumBreakpoint,p=e.user,m=e.viewer,f=Math.min(Math.round(t/n*100),100),h=f>=l.AccountMenuQuotaBarBreakpoints.OVERQUOTA,g=s.getUpsellText(f);return f<_?a.default.createElement("div",{className:"account-menu-v2__quota-wrapper"},a.default.createElement(c.Text,{size:"xsmall",color:"faint"},d.intl.formatMessage({id:"wkflKt",defaultMessage:"Your account has {allocated} storage"},{allocated:u.format_bytes(n)})),a.default.createElement(i.AccountMenuUpgradeButton,{user:p,viewer:m})):a.default.createElement("div",{className:"account-menu-v2__quota-wrapper"},a.default.createElement("div",{className:"account-menu-v2__quota-bar"},a.default.createElement("div",{className:"account-menu-v2__quota-bar-used",style:{width:f+"%"}})),a.default.createElement("div",null,h&&a.default.createElement(o.UIIcon,{src:r.WarningLine,size:"small",className:"account-menu-v2__quota-bar-icon"}),a.default.createElement(c.Text,{size:"xsmall",color:"faint"},d.intl.formatMessage({id:"KNYHMT",defaultMessage:"{count, plural, one{Using {used} of {allocated} storage} other{Using {used} of {allocated} storage}}"},{count:t,used:u.format_bytes(t),allocated:u.format_bytes(n)}))),g&&a.default.createElement(c.Text,{size:"xsmall",color:"faint"},g),a.default.createElement(i.AccountMenuUpgradeButton,{user:p,viewer:m}))},t})(a.default.Component)})),define("modules/clean/react/account_menu/account_menu_user_summary",["require","exports","tslib","react","dig-components/avatar","dig-components/buttons","dig-components/tooltips","dig-components/typography","modules/clean/em_string","modules/clean/react/account_menu/account_menu_quota_bar","modules/clean/react/account_menu/account_menu_types","modules/clean/react/account_menu/account_menu_util","modules/core/i18n","modules/core/user_i18n"],(function(e,t,n,a,o,r,c,u,l,i,s,d,_,p){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a),p=n.__importStar(p),t.AccountMenuUserSummary=function(e){var t=e.user,n=e.viewer,m=e.quotaBarMinimumBreakpoint,f=e.accountPhotoUrl,h=e.accountSpaceUsage,g=p.getInitials(t.display_name),v=l.Emstring.em_snippet(t.email,18,1);return a.default.createElement("div",{className:"account-menu-v2__user-summary"},a.default.createElement("div",{className:"account-menu-v2__user-summary-info"},a.default.createElement(r.Button,{variant:"transparent",hasNoUnderline:!0,className:"account-menu-v2__avatar-button account-menu-v2__change-photo",onClick:d.handleChangeAvatar,"aria-label":f?_.intl.formatMessage({id:"7VaQw6",defaultMessage:"Change photo"}):_.intl.formatMessage({id:"0UNJMJ",defaultMessage:"Add photo"})},a.default.createElement(o.Avatar,{role:"presentation",src:f,backgroundColor:o.avatarColorForUserIdentifier(g),className:"account-menu-v2__avatar",hasNoOutline:!0},g)),a.default.createElement("div",{className:"account-menu-v2__user-name"},a.default.createElement(u.Text,null,t.display_name),t.email===v?a.default.createElement(u.Text,{size:"xsmall",color:"faint"},v):a.default.createElement(c.Tooltip,{className:"account-menu-v2__tooltip",id:"user-email",title:t.email},a.default.createElement(u.Text,{size:"xsmall",color:"faint"},v)))),h.currentStatus!==s.AccountSpaceUsageStatus.NOT_APPLICABLE&&a.default.createElement(i.AccountMenuQuotaBar,{user:t,viewer:n,accountSpaceUsage:h,quotaBarMinimumBreakpoint:m}))}})),define("modules/clean/react/account_menu/account_menu_view",["require","exports","tslib","react","dig-components/avatar","dig-components/buttons","dig-components/menu","modules/clean/react/account_menu/account_menu_types","modules/clean/react/account_menu/account_menu_user_summary","modules/clean/react/account_menu/account_menu_util","modules/clean/react/css","modules/core/i18n","modules/core/user_i18n"],(function(e,t,n,a,o,r,c,u,l,i,s,d,_){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a),_=n.__importStar(_);var p=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return n.__extends(t,e),t.prototype.render=function(){var e=this.props,t=e.user,s=e.viewer,p=e.quotaBarMinimumBreakpoint,m=e.accountPhotoUrl,f=e.accountSpaceUsage,h=e.showChatLink,g=e.showInstallLink,v=e.onMenuSelection,S=_.getInitials(t.display_name);return a.default.createElement(c.Menu.Wrapper,{onToggle:i.handleMenuToggle,onSelection:v},(function(e){var _=e.getTriggerProps,v=e.getContentProps;return a.default.createElement(a.default.Fragment,null,a.default.createElement(r.Button,n.__assign({},_(),{variant:"transparent",hasNoUnderline:!0,className:"account-menu-v2__avatar-button account-menu-v2__trigger","aria-label":d.intl.formatMessage({id:"YPWjDD",defaultMessage:"Account menu"})}),a.default.createElement(o.Avatar,{alt:d.intl.formatMessage({id:"YPWjDD",defaultMessage:"Account menu"}),src:m,backgroundColor:o.avatarColorForUserIdentifier(S),className:"account-menu-v2__avatar account-menu-v2__avatar-header",size:"standard",hasNoOutline:!0},S)),a.default.createElement(c.Menu.Content,n.__assign({className:"account-menu-v2__content"},v(),{placement:"bottom-end"}),a.default.createElement(c.Menu.Segment,null,a.default.createElement(l.AccountMenuUserSummary,{user:t,accountPhotoUrl:m,accountSpaceUsage:f,viewer:s,quotaBarMinimumBreakpoint:p})),a.default.createElement(c.Menu.Segment,null,a.default.createElement(c.Menu.LinkItem,{key:u.AccountMenuSelectionOption.SETTINGS,href:i.SETTINGS_URL},d.intl.formatMessage({id:"x/c7tU",defaultMessage:"Settings"})),g&&a.default.createElement(c.Menu.ActionItem,{key:u.AccountMenuSelectionOption.INSTALL,value:u.AccountMenuSelectionOption.INSTALL},d.intl.formatMessage({id:"ruR+3P",defaultMessage:"Install Dropbox app"})),h&&a.default.createElement(c.Menu.ActionItem,{key:u.AccountMenuSelectionOption.CHAT,value:u.AccountMenuSelectionOption.CHAT},d.intl.formatMessage({id:"TBIxin",defaultMessage:"Chat with support"})),a.default.createElement(c.Menu.ActionItem,{key:u.AccountMenuSelectionOption.LOGOUT,value:u.AccountMenuSelectionOption.LOGOUT},d.intl.formatMessage({id:"3BZJoW",defaultMessage:"Sign out"})))))}))},t})(a.default.PureComponent),m=s.requireCssWithComponent(p,["/static/css/account_menu_v2-vfl44mLvJ.css","/static/css/dig-components/index.web-vflSjAPFK.css"]);t.AccountMenuView=m})),define("modules/clean/react/account_menu/account_menu_types",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),(function(e){e[e.LOADING=1]="LOADING",e[e.READY=2]="READY",e[e.NOT_APPLICABLE=3]="NOT_APPLICABLE"})(t.AccountSpaceUsageStatus||(t.AccountSpaceUsageStatus={})),(function(e){e.SETTINGS="settings",e.INSTALL="install",e.CHAT="chat",e.LOGOUT="logout"})(t.AccountMenuSelectionOption||(t.AccountMenuSelectionOption={})),(function(e){e[e.ALWAYS=0]="ALWAYS",e[e.STANDARD=50]="STANDARD",e[e.ALMOST_FULL=80]="ALMOST_FULL",e[e.OVERQUOTA=100]="OVERQUOTA"})(t.AccountMenuQuotaBarBreakpoints||(t.AccountMenuQuotaBarBreakpoints={}))})),define("modules/clean/react/account_menu/account_menu_upgrade_button",["require","exports","tslib","react","dig-components/buttons","modules/clean/analytics","modules/clean/react/account_menu/account_menu_util","modules/core/browser","modules/core/i18n"],(function(e,t,n,a,o,r,c,u,l){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=n.__importDefault(a),u=n.__importStar(u),t.getUpgradeButtonDestination=function(e,t){return e.is_team||!e.paid||t.role_exists("work")?e.is_team&&t.team_is_limited?c.BUSINESS_TRY_URL:c.UPGRADE_URL:c.BUSINESS_TRY_URL};var i=(function(e){function c(){var n=null!==e&&e.apply(this,arguments)||this;return n.handleUpgradeButtonClick=function(){var e=n.props,a=e.user,o=e.viewer,c=t.getUpgradeButtonDestination(a,o);r.GrowthEventsLogger.log("wb_profile_menu_upgrade_link",{action:"click",button_text:"UPGRADE",destination_url:c,location:"in_menu",version:"v2"}),u.redirect(c)},n}return n.__extends(c,e),c.prototype.componentDidMount=function(){var e=this.props,n=e.user,a=e.viewer;r.GrowthEventsLogger.log("wb_profile_menu_upgrade_link",{action:"view",button_text:"UPGRADE",destination_url:t.getUpgradeButtonDestination(n,a),location:"in_menu",version:"v2"})},c.prototype.render=function(){return a.default.createElement(o.Button,{className:"account-menu-v2__quota-bar-btn",onClick:this.handleUpgradeButtonClick,size:"small",variant:"transparent"},l.intl.formatMessage({id:"nkCWjP",defaultMessage:"Upgrade"}))},c})(a.default.Component);t.AccountMenuUpgradeButton=i})),define("modules/clean/react/account_menu/account_menu_util",["require","exports","tslib","modules/clean/analytics","modules/clean/react/account_menu/account_menu_types","modules/constants/trademark","modules/core/i18n","modules/core/uri","modules/clean/hql/index","dropbox/proto/hql_events/activation/activation","dropbox/proto/hql_events/extensions","dropbox/proto/hql_events/taxonomy"],(function(e,t,n,a,o,r,c,u,l,i,s,d){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var _=d.hql_events.TaxonomyAppSurface.AppSurface,p=d.hql_events.TaxonomyActionSurface.ActionSurface;t.getLogoutUrl=function(e){return new u.URI({scheme:"https",authority:"www.dropbox.com",path:"/logout",query:e?{cont:e}:void 0}).toString()},t.INSTALL_URL=new u.URI({scheme:"https",authority:"www.dropbox.com",path:"/install"}).toString(),t.SETTINGS_URL=new u.URI({scheme:"https",authority:"www.dropbox.com",path:"/account"}).toString(),t.UPGRADE_URL=new u.URI({scheme:"https",authority:"www.dropbox.com",path:"/plans",query:{trigger:"direct"}}).toString(),t.BUSINESS_TRY_URL=new u.URI({scheme:"https",authority:"www.dropbox.com",path:"/business/try",query:{_tk:"dropdown"}}).toString(),t.getAccountSpaceUsage=function(e,t){return t.serialized_sku_content.has_unlimited_space?{currentStatus:o.AccountSpaceUsageStatus.NOT_APPLICABLE}:"other"===e.allocation[".tag"]?{currentStatus:o.AccountSpaceUsageStatus.NOT_APPLICABLE}:{currentStatus:o.AccountSpaceUsageStatus.READY,used:e.used,allocated:e.allocation.allocated}},t.upsellLinks={UPGRADE_PLANS:{label:c.intl.formatMessage({id:"pvR+AO",defaultMessage:"Upgrade"}),href:t.UPGRADE_URL},TRY_BUSINESS:{label:c.intl.formatMessage({id:"KVRyHc",defaultMessage:"Try {trademark_business}"},{trademark_business:r.TRADEMARK_BUSINESS}),href:t.BUSINESS_TRY_URL}},t.handleChangeAvatar=function(){return n.__awaiter(void 0,void 0,void 0,(function(){return n.__generator(this,(function(t){switch(t.label){case 0:return[4,new Promise((function(t,n){e(["modules/clean/account_photo_modal/controller"],t,n)})).then(n.__importStar)];case 1:return t.sent().AccountPhotoModalController.show(),[2]}}))}))},t.handleMenuToggle=function(e){e.isOpen&&a.GrowthEventsLogger.log("wb_profile_menu",{action:"click",location:"in_menu",version:"v2"})},t.handleInstallClick=function(){a.GrowthEventsLogger.log("wb_profile_menu_install",{action:"click",location:"in_menu",version:"v2"}),l.logEvent({eventMessageName:"SelectDesktopAppInstallLink",event:i.hql_events.SelectDesktopAppInstallLink.create({action:"click",location:"in_menu",version:"v2",hqlMetadata:s.hql_events.HQLMetadata.create({appSurface:_.WEB,actionSurface:p.PROFILE_MENU})})})},t.getUpsellText=function(e){var t=void 0;return e>=o.AccountMenuQuotaBarBreakpoints.OVERQUOTA?t=c.intl.formatMessage({id:"YbxnDa",defaultMessage:"Free up space or upgrade now"}):e>=o.AccountMenuQuotaBarBreakpoints.ALMOST_FULL&&(t=c.intl.formatMessage({id:"MSmoKs",defaultMessage:"Upgrade soon to get more space"})),t}})),define("dropbox/proto/hql_events/retention/retention",["require","exports","tslib","protobufjs-dbx/minimal","dropbox/proto/hql_events/extensions"],(function(e,t,n,a){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var o,r=(a=n.__importStar(a)).Reader,c=a.Writer,u=a.util,l=a.roots.default||(a.roots.default={});t.default=l,t.hql_events=l.hql_events=((o=l.hql_events||{}).ShownPlusCancelSurveyModal=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.currentProductPlanType=u.Long?u.Long.fromBits(0,0,!1):0,e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.currentProductPlanType&&Object.hasOwnProperty.call(e,"currentProductPlanType")&&t.uint32(8).int64(e.currentProductPlanType),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&l.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(18).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new l.hql_events.ShownPlusCancelSurveyModal;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.currentProductPlanType=e.int64();break;case 2:a.hqlMetadata=l.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.ShownPlusCancelSurveyModal||{}),o.DismissPlusCancelSurveyModal=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&l.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(10).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new l.hql_events.DismissPlusCancelSurveyModal;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.hqlMetadata=l.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.DismissPlusCancelSurveyModal||{}),o.SelectExitButton=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&l.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(10).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new l.hql_events.SelectExitButton;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.hqlMetadata=l.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.SelectExitButton||{}),o.SelectSubmit=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.additionalInfo="",e.prototype.downgradeReasonId="",e.prototype.currentProductPlanType=u.Long?u.Long.fromBits(0,0,!1):0,e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.additionalInfo&&Object.hasOwnProperty.call(e,"additionalInfo")&&t.uint32(10).string(e.additionalInfo),null!=e.downgradeReasonId&&Object.hasOwnProperty.call(e,"downgradeReasonId")&&t.uint32(18).string(e.downgradeReasonId),null!=e.currentProductPlanType&&Object.hasOwnProperty.call(e,"currentProductPlanType")&&t.uint32(24).int64(e.currentProductPlanType),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&l.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(34).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new l.hql_events.SelectSubmit;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.additionalInfo=e.string();break;case 2:a.downgradeReasonId=e.string();break;case 3:a.currentProductPlanType=e.int64();break;case 4:a.hqlMetadata=l.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.SelectSubmit||{}),o.SelectSkip=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&l.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(10).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new l.hql_events.SelectSkip;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.hqlMetadata=l.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.SelectSkip||{}),o)})),define("dropbox/proto/hql_events/activation/activation",["require","exports","tslib","protobufjs-dbx/minimal","dropbox/proto/hql_events/extensions"],(function(e,t,n,a){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var o,r=(a=n.__importStar(a)).Reader,c=a.Writer,u=(a.util,a.roots.default||(a.roots.default={}));t.default=u,t.hql_events=u.hql_events=((o=u.hql_events||{}).SelectDesktopAppInstallLink=(function(e){function e(e){if(e)for(var t=Object.keys(e),n=0;n<t.length;++n)null!=e[t[n]]&&(this[t[n]]=e[t[n]])}return e.prototype.action="",e.prototype.location="",e.prototype.version="",e.prototype.hqlMetadata=null,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.action&&Object.hasOwnProperty.call(e,"action")&&t.uint32(10).string(e.action),null!=e.location&&Object.hasOwnProperty.call(e,"location")&&t.uint32(18).string(e.location),null!=e.version&&Object.hasOwnProperty.call(e,"version")&&t.uint32(26).string(e.version),null!=e.hqlMetadata&&Object.hasOwnProperty.call(e,"hqlMetadata")&&u.hql_events.HQLMetadata.encode(e.hqlMetadata,t.uint32(34).fork()).ldelim(),t},e.decode=function(e,t){e instanceof r||(e=r.create(e));for(var n=void 0===t?e.len:e.pos+t,a=new u.hql_events.SelectDesktopAppInstallLink;e.pos<n;){var o=e.uint32();switch(o>>>3){case 1:a.action=e.string();break;case 2:a.location=e.string();break;case 3:a.version=e.string();break;case 4:a.hqlMetadata=u.hql_events.HQLMetadata.decode(e,e.uint32());break;default:e.skipType(7&o)}}return a},e})(o.SelectDesktopAppInstallLink||{}),o)}));
//# sourceMappingURL=pkg-account_menu.min.js-vflq1ufbP.map