define(["require","exports","tslib","react","modules/clean/react/growth/continuous_onboarding/action_milestone_handlers","modules/clean/react/growth/continuous_onboarding/components/module_card/card_components"],(function(e,t,o,i,a,r){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),i=o.__importDefault(i),t.ActionTypeCardBody=function(e){var t=e.module.module_id,o=e.milestone,n=o.milestone_id,l=o.milestone_type_props,c=e.logger,s=e.markAsComplete,d=e.onSkipClick,m=e.cardBodyAccessibilityProps,u=e.userId,_=l,p=_.does_cta_complete_milestone,y=_.description,g=_.image_url,C=_.image_url_hi_res,k=_.image_alt,A=_.cta_text,b=_.button_style,f=_.action;return i.default.createElement(r.ModuleCardBody,{description:y,imageUrl:g,imageUrlHiRes:C,imageAlt:k,onCtaClick:function(){c.logMilestoneCtaClick(t,n),p&&s();var e=a.actionMilestoneHandlers[f[".tag"]];e&&e({userId:u,markAsComplete:s})},onSkipClick:d,ctaText:A,hasPrimaryCtaStyle:"primary"===b[".tag"],cardBodyAccessibilityProps:m})},t.ActionTypeCardBody.displayName="ActionTypeCardBody"}));
//# sourceMappingURL=action_card_body.min.js-vflU3pQgV.map