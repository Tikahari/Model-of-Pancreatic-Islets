define(["require","exports","tslib","modules/clean/api_v2/default_team_client","modules/clean/viewer","modules/core/browser","modules/clean/api_v2/types"],(function(e,r,t,n,o,i,a){"use strict";function s(){var e=o.Viewer.get_viewer().work_user;return e&&new n.DefaultTeamApiV2Client(e).ns("federation")}Object.defineProperty(r,"__esModule",{value:!0}),i=t.__importStar(i),r.createFederationClient=s;var c=s();r.CommonErrorTags={UserNotLoggedIn:"user_not_logged_in",NoPermission:"no_permission"},r.redirectOnTags=function(e,r){return void 0===r&&(r="/"),function(t){var n=t.error&&t.error[".tag"];throw n&&e.filter((function(e){return e===n})).length>0&&i.redirect(r),t}},r.redirectNotLoggedOrNoPermission=function(){return r.redirectOnTags([r.CommonErrorTags.UserNotLoggedIn,r.CommonErrorTags.NoPermission])},r.redirectNotLoggedIn=function(){return r.redirectOnTags([r.CommonErrorTags.UserNotLoggedIn])};var d=function(e){var r;return(r={})[a.ApiV2HeaderNames.DropboxTeamAuthorization]=JSON.stringify({auth_role:String(a.TeamAuthRequestRole.FederationAdminRole),auth_action_type:String(a.TeamAuthRequestActionType.OnBehalfOfAction)}),r[a.ApiV2HeaderNames.DropboxTeamId]=e,r};r.API={getInstancesPageData:function(){return null==c?void 0:c.rpc("get_instances_page_data",void 0,{}).catch(r.redirectNotLoggedOrNoPermission())},getSingleInstancesData:function(e){return null==c?void 0:c.rpc("get_single_instance_summary",void 0,{headers:d(e)}).catch(r.redirectNotLoggedIn())},listInstances:function(e){var t;return void 0===e&&(e=!1),null!==(t=null==c?void 0:c.rpc("list_instances",{include_federation:e},{}).catch(r.redirectNotLoggedOrNoPermission()))&&void 0!==t?t:Promise.resolve([])}}}));
//# sourceMappingURL=federation_api.min.js-vfl4zcFF_.map