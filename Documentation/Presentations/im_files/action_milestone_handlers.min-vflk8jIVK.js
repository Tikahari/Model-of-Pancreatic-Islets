define(["require","exports","tslib","modules/clean/viewer","modules/clean/react/growth/continuous_onboarding/types"],(function(e,n,r,t,o){"use strict";var i;Object.defineProperty(n,"__esModule",{value:!0}),n.actionMilestoneHandlers=((i={})[o.ActionKeys.TEST_ACTION]=function(){return r.__awaiter(void 0,void 0,void 0,(function(){return r.__generator(this,(function(e){return[2]}))}))},i[o.ActionKeys.SHARE_FOLDER]=function(n){var o=n.userId;return r.__awaiter(void 0,void 0,void 0,(function(){var n,i;return r.__generator(this,(function(a){switch(a.label){case 0:return[4,new Promise((function(n,r){e(["modules/clean/sharing/wizard/async_wizard_modals"],n,r)})).then(r.__importStar)];case 1:return n=a.sent().asyncShowShareAFolderWizardModal,i=t.Viewer.get_viewer().get_user_by_id(o),n(i),[2]}}))}))},i[o.ActionKeys.CONNECT_APPS]=function(n){var t=n.markAsComplete;return r.__awaiter(void 0,void 0,void 0,(function(){return r.__generator(this,(function(n){switch(n.label){case 0:return[4,new Promise((function(n,r){e(["modules/clean/react/growth/app_recommendations/app_recommendations_modal_loader"],n,r)})).then(r.__importStar)];case 1:return(0,n.sent().showAppRecommendationsModal)((function(){}),t),[2]}}))}))},i)}));
//# sourceMappingURL=action_milestone_handlers.min.js-vflfLcM3P.map