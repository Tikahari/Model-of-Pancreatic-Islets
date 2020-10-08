define(["require","exports","tslib","react","classnames","modules/clean/react/css","modules/core/exception","modules/clean/react/growth/continuous_onboarding/continuous_onboarding_reducer","modules/clean/react/growth/continuous_onboarding/hooks","modules/clean/react/growth/continuous_onboarding/components/completed_view","modules/clean/react/growth/continuous_onboarding/components/module_card_list","modules/clean/react/growth/continuous_onboarding/components/sidebar_expand_bar","modules/clean/react/growth/continuous_onboarding/components/sidebar_header","modules/clean/react/growth/continuous_onboarding/utils","modules/clean/react/growth/continuous_onboarding/logger"],(function(e,n,o,t,a,r,i,s,u,d,c,l,p,g,m){"use strict";Object.defineProperty(n,"__esModule",{value:!0}),t=o.__importDefault(t),a=o.__importDefault(a);var _=(function(e){function a(){var n=null!==e&&e.apply(this,arguments)||this;return n.state={hasError:!1},n}return o.__extends(a,e),a.getDerivedStateFromError=function(){return{hasError:!0}},a.prototype.componentDidCatch=function(e,n){this.props.onExpandChange&&this.props.onExpandChange(!1),i.reportException({err:e,severity:i.SEVERITY.CRITICAL,tags:["continuous_onboarding_web"],exc_extra:{component_stacktrace:n&&n.componentStack}})},a.prototype.render=function(){return this.state.hasError?null:t.default.createElement(n.ContinuousOnboardingNoCss,o.__assign({},this.props))},a})(t.default.PureComponent);n.ContinuousOnboardingErrorBoundary=_,n.ContinuousOnboardingNoCss=t.default.memo((function(e){var n=e.userId,o=e.isBackgroundActive,r=e.onExpandChange,i=t.default.useRef(new m.ContinuousOnboardingLogger).current,_=t.default.useReducer(s.reducer,s.initialState),h=_[0],b=_[1],f=h.isOpen,C=h.activeModuleId,E=h.showOpenButtonWhenCollapsed,y=h.progression,S=h.display_surface_props;if(u.useSidebarInitialization(i,b,n,o),u.useActiveBackgroundChange(i,b,o),u.useExpandChange(i,f,r),!S||!y)return null;var w=g.denormalizeProgressionModules(y),v=w.every((function(e){return!e.should_show})),x=!f&&!E;return t.default.createElement("aside",{className:a.default({"continuous-onboarding":!0,"continuous-onboarding--open":f}),"aria-hidden":x},E&&t.default.createElement(l.SidebarExpandBar,{isOpen:f,title:S.collapsed_title,handleOpen:function(){i.logSidebarManuallyExpanded(),b({type:s.Actions.OPEN_SIDEBAR})}}),t.default.createElement("div",{id:"continuous-onboarding-container",className:"continuous-onboarding__container","aria-hidden":!f},t.default.createElement(p.SidebarHeader,{title:S.expanded_title,handleCollapse:function(){i.logSidebarManuallyCollapsed(),b({type:s.Actions.CLOSE_SIDEBAR})}}),t.default.createElement(c.ModuleCardList,{userId:n,modules:w,implementationData:y.implementation_data,dispatch:b,activeModuleId:C,logger:i}),t.default.createElement(d.CompletedView,{isSidebarComplete:v,handleHideSidebar:function(){return b({type:s.Actions.HIDE_SIDEBAR})},emptyStateProps:S.empty_state_props,logger:i})))})),n.ContinuousOnboardingNoCss.displayName="ContinuousOnboarding",n.ContinuousOnboarding=r.requireCssWithComponent(_,["/static/css/growth/continuous_onboarding/continuous_onboarding-vfloMec32.css"])}));
//# sourceMappingURL=continuous_onboarding.min.js-vflMf185a.map