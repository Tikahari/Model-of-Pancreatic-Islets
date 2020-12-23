define(["require","exports","tslib","modules/clean/ajax","modules/clean/react/file_viewer/models","modules/clean/react/pass/constants","modules/clean/react/pass/action_timestamps"],(function(e,t,n,s,i,r,a){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),s=n.__importStar(s);var o={};o[r.EventTypes.PASS_SHOWN]="pass_shown",o[r.EventTypes.PASS_HOVER]="pass_hover",o[r.EventTypes.PASS_CLICK]="pass_click";var c=(function(){function e(){this.eventToHandlerStack={};for(var e=0,t=[r.EventTypes.PASS_SHOWN,r.EventTypes.PASS_HOVER,r.EventTypes.PASS_CLICK];e<t.length;e++){var n=t[e];this.eventToHandlerStack[n]=[]}}return e.prototype._log=function(e,t,n,r){var c=t?"BROWSE_FILE_FACEPILE":"PREVIEW_PAGE_FACEPILE",l={};if(!t){var _=i.FilePreviewSession.currentSession;r.file_viewer_session_id=_.fileViewerSession.id,r.file_preview_session_id=_.id,l=a.ActionTimestampsTracker.get(_.id)}var p=new Date,u={event_name:o[e],file_ns_id:n.ns_id,file_sjid:n.sjid,origin:c,product_surface:"file_preview",extra:JSON.stringify(r),action_timestamps:JSON.stringify(l),client_ts:p.getTime()/1e3};s.SilentBackgroundRequest({url:"/log/pass_facepile",data:u})},e.prototype.listenTo=function(e){this._unlistenToTopOfHandlersStack(e),this._pushHandlers(),this._listenToTopOfHandlersStack(e)},e.prototype.unlistenTo=function(e){this._unlistenToTopOfHandlersStack(e),this._popHandlers(),this._listenToTopOfHandlersStack(e)},e.prototype._unlistenToTopOfHandlersStack=function(e){for(var t in this.eventToHandlerStack)if(this.eventToHandlerStack.hasOwnProperty(t)){if(0===this.eventToHandlerStack[t].length)continue;var n=this.eventToHandlerStack[t].slice(-1)[0];e.removeListener(t,n)}},e.prototype._listenToTopOfHandlersStack=function(e){for(var t in this.eventToHandlerStack)if(this.eventToHandlerStack.hasOwnProperty(t)){if(0===this.eventToHandlerStack[t].length)continue;var n=this.eventToHandlerStack[t].slice(-1)[0];e.addListener(t,n)}},e.prototype._pushHandlers=function(){for(var e in this.eventToHandlerStack)if(this.eventToHandlerStack.hasOwnProperty(e)){var t=this._createHandlerFn(e);this.eventToHandlerStack[e].push(t)}},e.prototype._popHandlers=function(){for(var e in this.eventToHandlerStack)this.eventToHandlerStack.hasOwnProperty(e)&&this.eventToHandlerStack[e].pop()},e.prototype._createHandlerFn=function(e){var t=this;return function(n,s,i){t._log(e,n,s,{num_accessors:i.numAccessors,num_current_viewers:i.numCurrentViewers,num_viewers:i.numViewers,num_guests:i.numGuests,num_in_team_editors:i.numInTeamEditors,num_in_team_viewers:i.numInTeamViewers,num_non_team_editors:i.numNonTeamEditors,num_non_team_viewers:i.numNonTeamViewers,can_see_viewer_history:i.canSeeViewerHistory})}},e})();t.passFacepileLogger=new c}));
//# sourceMappingURL=pass_facepile_logger.min.js-vfltCanr8.map